#include <gtk/gtk.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include "acerca.c"

#define NUEVO 1
#define ABRIR 2
#define GUARDAR 3
#define GUARDAR_COMO 4
#define SALIR 5
#define CORTAR 6
#define COPIAR 7
#define PEGAR 8
#define ACERCA 9


GtkWidget *vista; /* vista */

/* sleccionará el texto */
GdkAtom sel_atom = GDK_SELECTION_CLIPBOARD;
GtkItemFactory *main_menu; 


void acerca(void); 



static void menu(gpointer data, guint op, GtkWidget *widget)
{
    GtkTextIter p; 
    
    switch(op) 
      {
      case NUEVO: /*nuevo archivo*/
	if(salvar_modif())   /* se guarda el archivo si abre uno nuevo */
	  {
	    /* Obtiene toda la tabla de etiquetas y las pone en el buffer */
	    buf = gtk_text_buffer_new(gtk_text_buffer_get_tag_table(buf));
	    gtk_text_view_set_buffer(GTK_TEXT_VIEW(vista), buf);
	    g_object_unref(G_OBJECT(buf)); 
            /* needed for freeing memory by the buffer wen a new buffer is created */
	  }
	break;
      case ABRIR: /*Abrir archivo*/
	if(salvar_modif()) 
        {
	  /* Guarda un archivo si se abre uno nuevo */
	  buf = gtk_text_buffer_new(gtk_text_buffer_get_tag_table(buf));
	  gtk_text_view_set_buffer(GTK_TEXT_VIEW(vista), buf);

	  g_object_unref(G_OBJECT(buf));
	  cargar(NULL);
	}
	break;
      case GUARDAR:
	salvar(nombre);
	break;
      case GUARDAR_COMO:
	salvar(NULL);
	break;
      case SALIR:
	if(salvar_modif())            /* Si se cierra un archivo, se preguntará si desea modificarlo */
	  gtk_widget_destroy(ventana);
	break;
      case CORTAR:
	gtk_text_buffer_cut_clipboard(buf,gtk_clipboard_get(sel_atom), TRUE);
	break;
      case COPIAR:
	gtk_text_buffer_copy_clipboard(buf,gtk_clipboard_get(sel_atom));
	break;
      case PEGAR:
      
	gtk_text_buffer_paste_clipboard(buf,gtk_clipboard_get(sel_atom), NULL, TRUE);
	break;
	
      case ACERCA:
        acerca();
        break;
	
      default:    
	g_printerr("Menu action not defined : %u\n", op);
	break;
      }
} 



/*Se crea nuestro menu*/

GtkItemFactoryEntry menu_def[] = 
  {
    { (char *)"/_Archivo", NULL, NULL, 0, (char *)"<Branch>", NULL },
    { (char *)"/Archivo/_Nuevo", (char *)"<control>N", menu, NUEVO, (char *)"<StockItem>", GTK_STOCK_NEW },
    { (char *)"/Archivo/_Abrir...", (char *)"<control>O", menu, ABRIR, (char *)"<StockItem>", GTK_STOCK_OPEN },
    { (char *)"/Archivo/_Guardar", (char *)"<control>S", menu, GUARDAR, (char *)"<StockItem>", GTK_STOCK_SAVE },
    { (char *)"/Archivo/Guardar como...", NULL, menu, GUARDAR_COMO, (char *)"<StockItem>", GTK_STOCK_SAVE_AS },
    { (char *)"/Archivo/sep", NULL, NULL, 0, (char *)"<Separator>", NULL },
    { (char *)"/Archivo/_Salir", (char *)"<control>Q", menu, SALIR, (char *)"<StockItem>", GTK_STOCK_QUIT },
    { (char *)"/_Editar", NULL, NULL, 0, (char *)"<Branch>", NULL },
    { (char *)"/Editar/Cortar", (char *)"<control>X", menu, CORTAR, (char *)"<StockItem>", GTK_STOCK_CUT },
    { (char *)"/Editar/_Copiar", (char *)"<control>C", menu, COPIAR, (char *)"<StockItem>", GTK_STOCK_COPY },
    { (char *)"/Editar/_Pegar", (char *)"<control>V", menu, PEGAR, (char *)"<StockItem>", GTK_STOCK_PASTE },
    { (char *)"/Acerca de",  NULL , menu, ACERCA, "<Item>" },
    
  };
