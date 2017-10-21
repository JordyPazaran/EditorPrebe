#include <gtk/gtk.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void acerca(void)
{

    GtkWidget *ventana1;
    GtkWidget *label;
/*Creamo nuestra ventana acerca de*/
    ventana1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (ventana1), "Acerca de ");
    gtk_window_set_default_size(GTK_WINDOW(ventana1), 300, 300);
  

    label = gtk_label_new ("Editor de texto Prebe\n En Gtk / C\nGeneración 35\n\nEquipo ?\nPrebes 12 y 13\n");
    
    gtk_container_add (GTK_CONTAINER (ventana1), label); 

    gtk_widget_show_all (ventana1);
}




