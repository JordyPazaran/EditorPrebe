#include <gtk/gtk.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "seleccionar.c"
#include "menu.c"



GtkWidget *vista; 
static void error(const gchar *msg)
{
    GtkWidget *dialogo; 

    dialogo = gtk_message_dialog_new(GTK_WINDOW(ventana), 0, GTK_MESSAGE_ERROR,
				    GTK_BUTTONS_OK, msg);
    gtk_dialog_run(GTK_DIALOG(dialogo));
    gtk_widget_destroy(dialogo); 
}




static gboolean eliminar(GtkWidget *widget, GdkEvent *event, gpointer data)
{
    return !salvar_modif();
}



int main(int argc, char *argv[])
{
    GtkWidget *caja, *scroll, *widget;
   
    GtkAccelGroup *accel;
      
    gtk_init(&argc, &argv);  /*Gtk toma argumentos tipo file*/

    ventana = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    /* Salir de la app*/  
    g_signal_connect(G_OBJECT(ventana), "delete_event",G_CALLBACK(eliminar), ventana);
    g_signal_connect(G_OBJECT(ventana), "destroy",G_CALLBACK(gtk_main_quit), NULL);
  

	/* Nombre y medidas de nuestro editor*/
    gtk_window_set_title(GTK_WINDOW(ventana), "Prebe Editor ");
    gtk_window_set_default_size(GTK_WINDOW(ventana), 800, 700); 
    
    caja = gtk_vbox_new(FALSE, 0); /* Contenedor de nuestro menú */
  
    gtk_container_add(GTK_CONTAINER(ventana), caja);
    
 
    accel = gtk_accel_group_new();
    gtk_window_add_accel_group(GTK_WINDOW(ventana), accel);
    

    main_menu = gtk_item_factory_new(GTK_TYPE_MENU_BAR, "<TextView>", accel);
    gtk_item_factory_create_items(main_menu,sizeof(menu_def) / sizeof(*menu_def),menu_def, NULL);
    

    widget = gtk_item_factory_get_widget(main_menu, "<TextView>");

    /* PAgregamos el menu en el contenedor  */
    gtk_box_pack_start(GTK_BOX(caja), widget, FALSE, FALSE, 0);
    
    scroll = gtk_scrolled_window_new(NULL, NULL); /* put a scroll window widget */

    /* Scroll en la ventana*/
    gtk_box_pack_start(GTK_BOX(caja), scroll, TRUE, TRUE, 0);
  
    /* Siguiente vusta*/
    vista = gtk_text_view_new();

    /* Creamos BUffer*/
    buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(vista));

    gtk_container_add(GTK_CONTAINER(scroll), vista);

    
    gtk_widget_show_all(ventana); /* muestra widgets de la ventana*/

    /* Error */
    g_set_printerr_handler(error);

    /* Carga archivo especificado*/
    if(argc > 1)
	cargar(g_strdup(argv[1]));

    /* Se esperan entradas de mouse y teclado*/
    gtk_main();

    return 0;
}
