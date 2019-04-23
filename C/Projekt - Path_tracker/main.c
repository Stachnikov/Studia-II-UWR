/*
    MIKOLAJ STACHNIK PROJECT - PHOTO TRACKER
*/
#include "declaration.h"


int main( int   argc,char *argv[] )
 {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL),*scroll_w,*Iframe,*Pframe;
    GtkWidget *grid,*subgrid,*Image_event,*Path_event;
    GtkWidget *menu,*bar;
    GtkWidget *SlideShow;
    GtkToolItem *New,*Open,*Save,*Sep,*Exit;
    GdkColor color;
    color.red = 26262;
    color.green = 0xffff;
    color.blue = 0;

//--WINDOW------------------------------------------------------------------------------------------------------------------------
    gtk_window_set_default_size(GTK_WINDOW(window),800,600);
    gtk_window_set_title(GTK_WINDOW(window),"Photo Tracker");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_window_set_resizable(GTK_WINDOW(window),FALSE);
    gtk_widget_modify_bg(GTK_WINDOW(window), GTK_STATE_NORMAL, &color);
    g_signal_connect(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);

//--BASE_IMAGE----------------------------------------------------------------------------------------------------------------------
    Image_event=gtk_event_box_new();

    pixbuf=gdk_pixbuf_new_from_file_at_scale_utf8("basic/start.png",500,500,0,&error);
    IMAG=gtk_image_new_from_pixbuf(pixbuf);
    gtk_container_add(GTK_CONTAINER(Image_event),IMAG);
    gtk_event_box_set_above_child(GTK_EVENT_BOX(Image_event),1);

    //IMAGE_FRAME
    Iframe=gtk_frame_new(NULL);
    gtk_frame_set_shadow_type(GTK_FRAME(Iframe),GTK_SHADOW_ETCHED_OUT);
    gtk_container_add(GTK_CONTAINER(Iframe),Image_event);
    gtk_container_set_border_width(GTK_CONTAINER(Iframe),4);
    gtk_frame_set_label(GTK_FRAME(Iframe),"CHOOSEN PHOTO");

//--ICON----------------------------------------------------------------------------------------------------------------------------
    error=NULL;
    pixbuf=gdk_pixbuf_new_from_file_utf8("basic/icon.png",&error);
    gtk_window_set_default_icon(pixbuf);

//--PATH--------------------------------------------------------------------------------------------------------------------------------------
    Path_event=gtk_event_box_new();

    pixbuf=gdk_pixbuf_new_from_file_at_scale_utf8("basic/mapa.png",500,-1,1,&error);
    PATH=gtk_image_new_from_pixbuf(pixbuf);
    gtk_container_add(GTK_CONTAINER(Path_event),PATH);
    gtk_event_box_set_above_child(GTK_EVENT_BOX(Path_event),1);

    //PATH_FRAME
    Pframe=gtk_frame_new(NULL);
    gtk_frame_set_shadow_type(GTK_FRAME(Pframe),GTK_SHADOW_ETCHED_OUT);
    gtk_container_add(GTK_CONTAINER(Pframe),Path_event);
    gtk_container_set_border_width(GTK_CONTAINER(Pframe),4);
    gtk_frame_set_label(GTK_FRAME(Pframe),"PATH");

//--SCROLLED_W-------------------------------------------------------------------------------------------------------------------------------
    scroll_w=gtk_scrolled_window_new(NULL,NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scroll_w),GTK_POLICY_AUTOMATIC,GTK_POLICY_AUTOMATIC);
    gtk_scrolled_window_set_min_content_width (GTK_SCROLLED_WINDOW(scroll_w),200);
    gtk_scrolled_window_set_min_content_height(GTK_SCROLLED_WINDOW(scroll_w),200);

    //LIST
    ListJPG=NULL;
    listview = create_view_and_model ();
    gtk_container_add (GTK_CONTAINER (scroll_w), listview);
    gtk_container_set_border_width(GTK_CONTAINER(scroll_w),4);
    GtkTreeSelection *selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(listview));
    gtk_tree_selection_set_mode(selection,GTK_SELECTION_SINGLE);
    g_signal_connect(G_OBJECT(selection),"changed",G_CALLBACK(showIMG),NULL);

//--MENU---------------------------------------------------------------------------------------------------------------------------
    menu = gtk_box_new(GTK_ORIENTATION_VERTICAL,4);

    //BAR
    bar = gtk_toolbar_new();
    gtk_toolbar_set_style(GTK_TOOLBAR(bar), GTK_TOOLBAR_ICONS);
    gtk_container_set_border_width(GTK_CONTAINER(bar),4);

    //NEW
    New = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
    gtk_toolbar_insert(GTK_TOOLBAR(bar), New, -1);

    //OPEN
    Open = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
    gtk_toolbar_insert(GTK_TOOLBAR(bar), Open, -1);

    //SAVE
    Save = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
    gtk_toolbar_insert(GTK_TOOLBAR(bar), Save, -1);

    //SEP
    Sep = gtk_separator_tool_item_new();
    gtk_toolbar_insert(GTK_TOOLBAR(bar), Sep, -1);

    //EXIT
    Exit = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
    gtk_toolbar_insert(GTK_TOOLBAR(bar), Exit, -1);

    //PACK AND SIGNAL
    gtk_box_pack_start(GTK_BOX(menu), bar, FALSE, FALSE, 5);
    g_signal_connect(G_OBJECT(Exit), "clicked", G_CALLBACK(gtk_main_quit), NULL);
    g_signal_connect(G_OBJECT(Open), "clicked", G_CALLBACK(iterr=ListJPG=chooseJPG), NULL);
    g_signal_connect(G_OBJECT(New), "clicked", G_CALLBACK(Fnew), NULL);
    g_signal_connect(G_OBJECT(Save), "clicked", G_CALLBACK(Fsave), NULL);
    g_signal_connect(G_OBJECT(Image_event),"button_press_event",G_CALLBACK(next_image),NULL);

//--SLIDESHOW----------------------------------------------------------------------------------------------------------------------
    GtkWidget *MANUAL;

    MANUAL=gtk_tool_button_new_from_stock(GTK_STOCK_DIALOG_INFO);
    g_signal_connect(G_OBJECT(MANUAL), "clicked", G_CALLBACK(manual), NULL);

//--GRID---------------------------------------------------------------------------------------------------------------------------
    grid=gtk_grid_new();
    subgrid=gtk_grid_new();
    gtk_grid_attach(GTK_GRID(grid),menu,0,0,1,1);
    gtk_grid_attach(GTK_GRID(grid),MANUAL,1,0,1,1);
    gtk_grid_attach(GTK_GRID(grid),Iframe,0,1,1,1);
    gtk_grid_attach(GTK_GRID(grid),subgrid,1,1,1,1);
    gtk_grid_attach(GTK_GRID(subgrid),scroll_w,0,0,1,1);
    gtk_grid_attach(GTK_GRID(subgrid),Pframe,0,1,1,1);

    gtk_container_add(GTK_CONTAINER(window),grid);

//--GTK_LOOP------------------------------------------------------------------------------------------------------------------------
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

