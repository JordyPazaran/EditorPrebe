Editor de texto programado en C usando GTK
==========================================
Este editor cuenta con las funciones principales de cualquier editor de texto disponible en la red
+ Para su elavoración se usó librerías de GTK y se consultó su [DOCUMENTACIÓN](https://developer.gnome.org/gtk3/stable/gtk-getting-started.html)
+ Para poder compilar y correr el programa es necesario contar tener instalado *GTK 2.0 o +" y "trabajar en un istema UNIX"

Funciones del editor de texto
-----------------------------

Como se menciona, el editor cuenta con funciones principales:
+ Crear nuevo archivo
+ Abrir y editar archivo existente
+ Copiar
+ Pegar
+ Cortar
+ Guardar
+ Guardar como

Compilar y Ejecutar editor de texto
-----------------------------------

Para poder hacer uso del editor de texto es necesario instalar GTK 2.0 y contar con un sistema Unix, de lo contario no se podrá ejectutar

### Instalar
Para instalar GTK y sus librerías correspondinetes ingresar en la terminal:
```
sudo apt-get install libgtk-2-dev
```
### Compilación y ejecucio+ón
+ Compilar
```
gcc editor.c -Wall -ansi -o Prebes `pkg-config --cflags --libs gtk+-2.0`
```
+ Ejecución
```
./Prebes
```
## Para la elaboración de este Editor se consultaron varios ejemplos de internet y se utilió métodos como el de selector, implementándolo a nuestro programa.
