#ifndef DECLARATIONS
#define DECLARATIONS

#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <libexif/exif-data.h>
#include <libexif/exif-log.h>
#include <libexif/exif-mem.h>
#include <libexif/exif-loader.h>

    GtkImage *PATH;
    GtkImage *IMAG;
    GdkPixbuf *pixbuf;
    GError *error;
    GSList *ListJPG;
    GtkWidget *listview;
    GSList *iterr;
    GtkWidget *eventbox;


    void show_error(GtkWidget *widget, gpointer window);
    void Fsave(GtkWidget *widget, gpointer data);
    void Create_GPX();
    GSList *chooseJPG(GtkWidget *widget, gpointer window);
    void quit( GtkWidget *widget,gpointer data);
    void Fnew(GtkWidget *menu_item,gpointer data);
    GtkTreeModel *create_and_fill_model (GSList *ListJPG);
    GtkWidget *create_view_and_model ();
    char *get_date(char *path);
    float get_lat(char *path);
    float get_lon(char *path);
    void set_path(GSList *ListJPG);
    void showIMG(GtkWidget *widget,gpointer data);
    void unfscreen(GtkWidget *Button, GtkWidget *Slidewindow);
    void fscreen(GtkWidget *button);
    void next_image(GtkWidget *button);
    void manual(GtkWidget *widget, gpointer window);

#endif // DECLARATIONS
