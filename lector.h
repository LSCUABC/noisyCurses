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

	
	getmaxyx(stdscr,yy,xx);
	
	if(fexists(arch))
		f=fopen(arch,"r");
	else{
		perror("No existe el archivo");
		return;
	}
	//liz
		getmaxyx(l,ly,lx);
		mvwprintw(l,1,24-(strlen(can)/2),"%s",can);
                mvwprintw(l,1,55-(strlen(art)/2),"%s",art);
                mvwprintw(l,1,22+(xx/2)-(strlen(alb)/2),"%s",alb);
		mvwprintw(l,ly-3,1,"<F8 ");
		mvwprintw(l,ly-3,lx-5," F9>");
		mvwprintw(l,ly-2,1,"[RETROCEDER]");
		mvwprintw(l,ly-2,lx-10,"[AVANZAR]");
		
		getmaxyx(m,my,mx);
		mvwprintw(m,my-2,(mx/2)+7,"F10[ALEATORI0]  CTRL+Z[SALIR]");

		mvwhline(l,2,0,0,xx);
		box(l,0,0);



	//liz
	
	
	do{
				
        fgets(n[x].a,sizeof(n[x].a),f);
        n[x].a[strlen(n[x].a)-1]='\0';
		
		if(feof(f))
			break;
			
        fgets(n[x].al,sizeof(n[x].al),f);
        n[x].al[strlen(n[x].al)-1]='\0';		

		fgets(n[x].t,sizeof(n[x].t),f);
		n[x].t[strlen(n[x].t)-1]='\0';

		fgets(linea,sizeof(linea),f);
		n[x].m=atoi(linea);


		fgets(linea,sizeof(linea),f);
		n[x].s=atoi(linea);		
		
		
		mvwprintw(l,3+x,24-(strlen(n[x].t)/2),"%s",n[x].t);
		mvwprintw(l,3+x,55-(strlen(n[x].a)/2),"%s",n[x].a);
		mvwprintw(l,3+x,22+((xx/2)-(strlen(n[x].al)/2)),"%s",n[x].al);
		mvwprintw(l,3+x,4,"%d)",x+1);
		mvwprintw(l,3+x,xx-15,"%d:%d",n[x].m,n[x].s);
		
		wrefresh(l);
		refresh();		

		x++;
		
		}while(1);
		
		
		hl=aplayer(l);
		refresh();
		
		np=nplaying(hl,n[hl-1],p,m);
		wattroff(stdscr,A_REVERSE);
		
		fclose(f);
	}

#endif
