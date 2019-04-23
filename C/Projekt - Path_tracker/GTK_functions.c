#include "declaration.h"

void manual(GtkWidget *widget, gpointer window)
{
    GtkWidget *dialog = gtk_about_dialog_new();
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("/basic/icon.png", NULL);

    gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(dialog), "PATH TRACKER");
    gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), "1.0");
    gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), "Mikolaj Stachnik");
    gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), "Program to create a path from photos\n\tMore info in documentation.pdf");
    gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog), pixbuf);
    g_free(pixbuf);
    gtk_dialog_run(GTK_DIALOG (dialog));
    gtk_widget_destroy(dialog);
}

//---SAVE_GPX_FILE------------------------------------------------------------------------------------------------------------------
void Fsave(GtkWidget *widget, gpointer window)
{
    GtkWidget *dialog;

    //DIALOG
    dialog = gtk_file_chooser_dialog_new ("Save gpx track to file...", GTK_WINDOW(window), GTK_FILE_CHOOSER_ACTION_SAVE, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT, NULL);

    if (gtk_dialog_run (GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        char *filename;
        GtkFileChooser *chooser = GTK_FILE_CHOOSER (dialog);
        gtk_file_chooser_set_filename (chooser,"track.gpx");
        filename = gtk_file_chooser_get_filename (chooser);
        if (strstr(filename,".gpx")!=NULL)
            Create_GPX(filename);
        else
        {
            show_error(widget,window);
        }
    }

    gtk_widget_destroy (dialog);
    return ListJPG;
}

//--WRITE_GPX------------------------------------------------------------------------------------------------------------------------
void Create_GPX(char *filename)
{
    //OPEN NEW FILE
    FILE *f = fopen(filename, "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    //GPX
    char *text = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<gpx version=\"1.0\">\n\t<name>Example gpx</name>";
    fprintf(f, "%s\n", text);

        //WAYPOINTS
        GSList *iteratio=ListJPG;
        char* path;
        float lon,lat;
        while(iteratio!=NULL)
        {
            path = iteratio->data;
            lon=get_lon(path);
            lat=get_lat(path);
            fprintf(f, "\t\t<wpt lat=\"%f\" lon=\"%f\"> </wpt>\n", lat, lon);
            iteratio=g_slist_next(iteratio);
        }

        //TRACK
        text = "\t<trk><name>Example gpx</name><number>1</number><trkseg>";
        fprintf(f, "%s\n", text);

        iteratio=ListJPG;
        while(iteratio!=NULL)
        {
            path = iteratio->data;
            lon=get_lon(path);
            lat=get_lat(path);
            fprintf(f, "\t\t<trkpt lat=\"%f\" lon=\"%f\"></trkpt>\n", lat, lon);
            iteratio=g_slist_next(iteratio);
        }

        //END_GPX
        text="\t</trkseg></trk>\n</gpx>";
        fprintf(f, "%s\n", text);

    g_free(path);
    fclose(f);
}

//--DISPLAYING_NEW_IMAGE------------------------------------------------------------------------------------------------------------------------
void next_image(GtkWidget *button)
{
        GdkPixbuf *buff;
        char* path;
        iterr=g_slist_next(iterr);
        if(iterr!=NULL)
        {
            path=iterr->data;
            buff=gdk_pixbuf_new_from_file(path,&error);
            buff=gdk_pixbuf_scale_simple(buff, 500, 500, GDK_INTERP_BILINEAR);
            gtk_image_set_from_pixbuf(IMAG,buff);
        }
        else
        {
            iterr=ListJPG;
            if(iterr!=NULL)
            {
                path=iterr->data;
                buff=gdk_pixbuf_new_from_file(path,&error);
                buff=gdk_pixbuf_scale_simple(buff, 500, 500, GDK_INTERP_BILINEAR);
                gtk_image_set_from_pixbuf(IMAG,buff);
            }
        }
}


//--DRAWING_A_PATH_AND_DISPLAYING_IT_AS_A_PATH_IMAGE------------------------------------------------------------------------------------------------------------------------
void set_path(GSList *ListJPG)
{
    GSList *itera=ListJPG;
    cairo_surface_t *surface;
    cairo_t *cr;
    surface=cairo_image_surface_create_from_png("basic/mapa.png");
    cr = cairo_create (surface);

    //LINES
    cairo_set_line_cap(cr,CAIRO_LINE_CAP_ROUND);
	cairo_set_line_join(cr,CAIRO_LINE_JOIN_ROUND);
	cairo_set_line_width (cr, 3);
	cairo_set_source_rgb (cr, 0, 0, 0);

    char *path;
    float lat,lon;
    path = itera->data;
    lat=get_lat(path);
    lon=get_lon(path);

    cairo_move_to (cr, 360.0+2*(lon), 180.0-2*(lat));
    itera=g_slist_next(itera);
    while(itera!=NULL)
    {
        path = itera->data;
        lat=get_lat(path);
        lon=get_lon(path);
        if(lat!=(-1000) && lon!=(-1000))
            cairo_line_to (cr, 360.0+2*(lon), 180.0-2*(lat));
        itera=g_slist_next(itera);
    }
    cairo_stroke(cr);

    //POINTS
    cairo_set_line_width (cr, 8);
	cairo_set_source_rgb (cr, 255, 0, 0);
	itera=ListJPG;
    while(itera!=NULL)
    {
        path = itera->data;
        lat=get_lat(path);
        lon=get_lon(path);
        if(lat!=(-1000) && lon!=(-1000))
        {
            cairo_move_to (cr, 360.0+2*(lon), 180.0-2*(lat));
            cairo_close_path(cr);
            cairo_stroke(cr);
        }
        itera=g_slist_next(itera);
    }
        cairo_surface_write_to_png (surface, "basic/path.png");
        cairo_destroy (cr);
        cairo_surface_destroy (surface);
}

//--TREE------------------------------------------------------------------------------------------------------------------------
    enum
    {
      COL_ICON,
      COL_NAME,
      COL_DATE,
      COL_LAT,
      COL_LON,
      NUM_COLS
    } ;


    GtkTreeModel *create_and_fill_model (GSList *ListJPG)
    {
      GtkListStore  *store;
      GtkTreeIter    iter;

      store = gtk_list_store_new (NUM_COLS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_FLOAT, G_TYPE_FLOAT,G_TYPE_FLOAT);


        GSList *itera=ListJPG;

        while(itera!=NULL)
        {
            GtkCellRenderer *renderer;
            char *path,*name,*date;
            float lat,lon,alt;
            path = itera->data;
            name=strrchr(path,92)+1;
            date=get_date(path);
            lat=get_lat(path);
            lon=get_lon(path);

            if(lat!=(-1000) && lon!=(-1000) && strcmp(date,"ERROR")!=0)
            {
                gtk_list_store_append (store, &iter);
                gtk_list_store_set (store, &iter,
                              COL_ICON, path,
                              COL_NAME, name,
                              COL_DATE, date,
                              COL_LAT, lat,
                              COL_LON, lon,
                              -1);
            }
            itera=g_slist_next(itera);
        }

      return GTK_TREE_MODEL (store);
    }

    GtkWidget *create_view_and_model ()
    {
      GtkCellRenderer     *renderer;
      GtkTreeModel        *model;
      GtkWidget           *view;

      view = gtk_tree_view_new ();

      // --- Column #1 --- is hidden

      // --- Column #2 ---

      renderer = gtk_cell_renderer_text_new ();
      gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),
                                                   -1,
                                                   "NAME",
                                                   renderer,
                                                   "text", COL_NAME,
                                                   NULL);
      // --- Column #3 ---

      renderer = gtk_cell_renderer_text_new ();
      gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),
                                                   -1,
                                                   "DATE",
                                                   renderer,
                                                   "text", COL_DATE,
                                                   NULL);
    // --- Column #4 ---

      renderer = gtk_cell_renderer_text_new ();
      gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),
                                                   -1,
                                                   "LATITUDE",
                                                   renderer,
                                                   "text", COL_LAT,
                                                   NULL);
    // --- Column #5 ---

      renderer = gtk_cell_renderer_text_new ();
      gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (view),
                                                   -1,
                                                   "LONGTITUDE",
                                                   renderer,
                                                   "text", COL_LON,
                                                   NULL);

      model = create_and_fill_model (ListJPG);

      gtk_tree_view_set_model (GTK_TREE_VIEW (view), model);

      g_object_unref (model);
      return view;
    }
//END_OF_TREE


//--FILECHOOSER_TO_PICK_.JPG_FILES------------------------------------------------------------------------------------------------------------------------
GSList *chooseJPG(GtkWidget *widget, gpointer window)
{
    GtkWidget *dialog,*imgfilter;
    imgfilter=gtk_file_filter_new();

    //ONLY_JPG_ALLOWED
    gtk_file_filter_add_mime_type(GTK_FILE_FILTER(imgfilter),"image/jpeg");
    gtk_file_filter_set_name(GTK_FILE_FILTER(imgfilter),"Only .jpg");

    //DIALOG
    dialog = gtk_file_chooser_dialog_new ("Choose files...", GTK_WINDOW(window), GTK_FILE_CHOOSER_ACTION_OPEN, GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, NULL);
    gtk_file_chooser_set_select_multiple(GTK_FILE_CHOOSER(dialog), TRUE);
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog),GTK_FILE_FILTER(imgfilter));

    if (gtk_dialog_run (GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        GtkTreeModel *model;
        ListJPG=gtk_file_chooser_get_filenames (GTK_FILE_CHOOSER(dialog));
        model=create_and_fill_model(ListJPG);
        gtk_tree_view_set_model(GTK_TREE_VIEW(listview),GTK_TREE_MODEL(model));
        set_path(ListJPG);
        pixbuf=gdk_pixbuf_new_from_file_at_scale_utf8("basic/path.png",500,-1,1,&error);
        gtk_image_set_from_pixbuf(PATH,pixbuf);

        char* path;
        GdkPixbuf *buff;
        iterr=ListJPG;
        if(iterr!=NULL)
        {
            path=iterr->data;
            buff=gdk_pixbuf_new_from_file(path,&error);
            buff=gdk_pixbuf_scale_simple(buff, 500, 500, GDK_INTERP_BILINEAR);
            gtk_image_set_from_pixbuf(IMAG,buff);
        }
    }

    if(error != NULL)
    {
        printf("%s\n", error->message);
        error=NULL;
        show_error(widget,window);
        pixbuf=gdk_pixbuf_new_from_file_at_scale_utf8("basic/start.png",500,500,0,&error);
        gtk_image_set_from_pixbuf(IMAG,pixbuf);
    }
    gtk_widget_destroy (dialog);
    return ListJPG;
}

//--NEW_PROJECKT_INITIALIZATION------------------------------------------------------------------------------------------------------------------------
void Fnew(GtkWidget *menu_item,gpointer data)
{
    GtkTreeModel *model;
    pixbuf=gdk_pixbuf_new_from_file("basic/start.png",&error);
    pixbuf=gdk_pixbuf_scale_simple(pixbuf,500,500,GDK_INTERP_BILINEAR);
    gtk_image_set_from_pixbuf(IMAG,pixbuf);
    ListJPG=NULL;
    model=create_and_fill_model(ListJPG);
    gtk_tree_view_set_model(GTK_TREE_VIEW(listview),GTK_TREE_MODEL(model));
    pixbuf=gdk_pixbuf_new_from_file_at_scale("basic/mapa.png",500,-1,1,&error);
    gtk_image_set_from_pixbuf(PATH,pixbuf);
    iterr=NULL;
}

//--SHOW_ERROR_WINDOW------------------------------------------------------------------------------------------------------------------------
void show_error(GtkWidget *widget, gpointer window)
{
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(GTK_WINDOW(window),
                                    GTK_DIALOG_DESTROY_WITH_PARENT,
                                    GTK_MESSAGE_ERROR,
                                    GTK_BUTTONS_OK,
                                    "ERROR: %s", "NOT A GPX FILE...\nYOU NEED TO ADD .GPX TO GIVEN NAME");
    gtk_window_set_title(GTK_WINDOW(dialog), "ERROR");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

//--CHOOSEN_PHOTO_IS_DISPLAYED_ON_IMAG_WINDOW------------------------------------------------------------------------------------------------------------------------
void showIMG(GtkWidget *widget,gpointer data)
{
  GtkTreeSelection *selection;
  GtkTreeModel     *modelselect;
  GtkTreeIter       selected;

  selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(listview));
  if (gtk_tree_selection_get_selected(selection, &modelselect, &selected))
  {
    gchar *name;

    gtk_tree_model_get (modelselect, &selected, COL_ICON, &name, -1);
    pixbuf=gdk_pixbuf_new_from_file(name,&error);
    pixbuf=gdk_pixbuf_scale_simple(pixbuf,500,500,GDK_INTERP_BILINEAR);
    gtk_image_set_from_pixbuf(IMAG,pixbuf);

    g_free(name);
  }
}

//--MAIN_QUIT------------------------------------------------------------------------------------------------------------------------
void quit( GtkWidget *widget,gpointer data)
{
    g_slist_free(ListJPG);
    gtk_main_quit();
}
