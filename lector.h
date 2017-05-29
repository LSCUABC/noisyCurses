#ifndef lector_h
#define lector_h

#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "global.h"
#include "aplayer.h"

void lector(char arch[],WINDOW *m,WINDOW *p,WINDOW *l){
	FILE *f;
	WINDOW *opcion;
	int np=0,hl=0,c=0,a=2,b=2,x=0,xx=0,my=0,mx=0,yy=0,ly=0,lx=0;
	char linea[1024],ch,can[8]="CANCION",art[8]="ARTISTA",alb[7]="ALBUM";

	
	getmaxyx(stdscr,yy,xx); // obtenemos las dimensiones de la terminal en que estamos
	
	if(fexists(arch)) // veryficamos que el archivo con el nombre "$arch" existe
		f=fopen(arch,"r"); // si existe lo abrimos para lectura
	else{
		perror("No existe el archivo"); // sino existe manda error y sale del programa
		return;// aun no se implementa una forma segura de retornar la silda del programa ya que el main es un ciclo infinito...
	}
	//liz
		getmaxyx(l,ly,lx); //obtenemos las dimensiones actuales de la ventana de listado de canciones
		mvwprintw(l,1,24-(strlen(can)/2),"%s",can);// Imprimimos titulos para las columnas 1) CANION
                mvwprintw(l,1,55-(strlen(art)/2),"%s",art);// 2) ARTISTA 
                mvwprintw(l,1,22+(xx/2)-(strlen(alb)/2),"%s",alb);// 3) ALBUM
		mvwprintw(l,ly-3,1,"<F8 ");// Imprimimos ayuda visual para el ususarion
		mvwprintw(l,ly-3,lx-5," F9>");// F9[AVANZAR]
		mvwprintw(l,ly-2,1,"[RETROCEDER]");// F8[RETROCEDER]
		mvwprintw(l,ly-2,lx-10,"[AVANZAR]");
		
		getmaxyx(m,my,mx);// obtenemos las dimensiones actuales de la ventana de control
		mvwprintw(m,my-2,(mx/2)+7,"F10[ALEATORI0]  CTRL+Z[SALIR]"); // Imprime ayuda visual para el usuario
									    // F10[ALEATORIO] CTRL+Z[SALIR]

		mvwhline(l,2,0,0,xx);// imprime una linea horizontal que separa el titulo de las columnas de el listado de cancionces en la ventana de listado de canciones.
		box(l,0,0);// volvemos a bordear a la ventana de listado ya que la linea horizontal se imprime hasta las orrilas de la ventana volviendolo visualmente desagradable. 



	//liz
	
	
	do{
				
        fgets(n[x].a,sizeof(n[x].a),f);	// lee del archivo n caracteres y guardalos como nombre del artista en cuestion	
        n[x].a[strlen(n[x].a)-1]='\0'; // agrega nulo a la ultima posicion del string capturado just in case..
		
		if(feof(f))	// Si se llego al EOF entonces break
			break;		// Break nos saca de ciclo infinito 
			
		fgets(n[x].al,sizeof(n[x].al),f);//lee del archivo n caracteres y guarda como nombre de album en cuestion 
		n[x].al[strlen(n[x].al)-1]='\0';// agrega nulo a la ultima posicion del string capturado just in case..		
		fgets(n[x].t,sizeof(n[x].t),f);//lee del archivo n caracteres y guarda como nombre de cancion en cuestion 
		n[x].t[strlen(n[x].t)-1]='\0';// agrega nulo a la ultima posicion del string capturado just in case..

		fgets(linea,sizeof(linea),f);//lee del archivo 1024 caracteres y guarda como linea actual
		n[x].m=atoi(linea);// parsa el string linea a integro si es posible guarda el resultado en min de la cancion 


		fgets(linea,sizeof(linea),f);//lee del archivo 1024 caracteres y guarda como linea actual
		n[x].s=atoi(linea);// parsa el string linea a integro si es posible guarda el resultado en seg de la cancion		
		
		
		mvwprintw(l,3+x,24-(strlen(n[x].t)/2),"%s",n[x].t);
		mvwprintw(l,3+x,55-(strlen(n[x].a)/2),"%s",n[x].a);
		mvwprintw(l,3+x,22+((xx/2)-(strlen(n[x].al)/2)),"%s",n[x].al);
		mvwprintw(l,3+x,4,"%d)",x+1);
		mvwprintw(l,3+x,xx-15,"%d:%d",n[x].m,n[x].s);
	
		//Imprime el Listado de canciones recien leido
	
		wrefresh(l);// window refresh lista
		refresh();// refresh all windows		

		x++;
		
		}while(1);// por siempre si no se cumple la condicion
		
		
		hl=aplayer(l);// invoca a aplayer y manda su valor de retorno a int hl
		refresh();// refresh todo
		
		np=nplaying(hl,n[hl-1],p,m);// invoca nplaying y manda su valor de retorno a int np
		wattroff(stdscr,A_REVERSE);// apaga el atributo de color inverso
		
		fclose(f);// cierra el archivo en cuestion
	}

#endif
