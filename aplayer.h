#ifndef aplayer_h
#define aplayer_h

#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "global.h"


int n_choices=6;
void menu(WINDOW *c,int op);
int aplayer(WINDOW *m){
		int hl=1,choice=0,xx,yy,c;	
		int ra=0;
		getmaxyx(stdscr,yy,xx);// dimensiones de terminal a yy y xx
		
		keypad(m,TRUE);// En la ventana m las teclas F1-F12,ENTER,KEY_(UP,DOWN,LEFT,RIGHT) se leen como caracteres
		noecho();// No escribas en pantalla lo que ingreso en el teclado
		cbreak();// getch no esperan una entrada del usuario 
		
		menu(m,hl);
		while(1){
		c=wgetch(m);// window getch hacia int c
		
		switch(c){
			
			case KEY_UP:
				if(hl==1) // si le picas hacia arriba y ya estas bn arriba vas pa abajo
					hl=7;
				else
					--hl;// sino nel
			break;
			
			case KEY_DOWN:// mismo pero alrreves
				if(hl==7)
					hl=1;
				else
					++hl;				
			break;
			
			case 10:
				choice=hl;// if ENTER entonces esa es la seleccion
			break;
			
			case KEY_F(10): //key utiliza para que el F10 es una seleccion de canciones random
				hl=rand()%8;
				choice=hl;
			break;
			case KEY_F(8):// Key utilizada para cambiar la lista de reproduccion actual
				refresh();
				system("cp wav.lst wav.now&&cp wav.prev wav.lst &&cp wav.now wav.prev");
			break;
			case KEY_F(9):// mismo
				refresh();
				system("cp wav.lst wav.now&&cp wav.nxt wav.lst&&cp wav.now wav.nxt");
			break;
			default:
		        getmaxyx(stdscr,yy,xx);	// refresh dimensiones de terminal 
			refresh();
			break;
		}
		menu(m,hl);// invoca a menu
		if(choice!=0)
			break;
			
	}		
	clrtoeol();
	refresh();
		
return hl;
};

menu(WINDOW *c,int op){
	int i,y,x,xx,yy;
	
	getmaxyx(stdscr,yy,xx);
	i=y=3;
	for(x=0;x<7;++x){
		if(op==x+1){
			wattron(c,A_REVERSE);
			mvwprintw(c,y,24-(strlen(n[x].t)/2),"%s",n[x].t);
			mvwprintw(c,y,55-(strlen(n[x].a)/2),"%s",n[x].a);
			mvwprintw(c,y,22+((xx/2)-(strlen(n[x].al)/2)),"%s",n[x].al);
			mvwprintw(c,y,4,"%d)",x+1);
			mvwprintw(c,y,xx-15,"%d:%d",n[x].m,n[x].s);
			wattroff(c,A_REVERSE);
			}
		else{
			mvwprintw(c,y,24-(strlen(n[x].t)/2),"%s",n[x].t);
			mvwprintw(c,y,55-(strlen(n[x].a)/2),"%s",n[x].a);
			mvwprintw(c,y,22+((xx/2)-(strlen(n[x].al)/2)),"%s",n[x].al);
			mvwprintw(c,y,4,"%d)",x+1);
			mvwprintw(c,y,xx-15,"%d:%d",n[x].m,n[x].s);
			}
		++y;
		}// solo ressalta la opcion seleccionada al borrarla y reescribirla en negritas...
	wrefresh(c);// window refresh listado
	
	}
#endif

			break;
			case KEY_F(8):
				refresh();
				system("cp wav.lst wav.now&&cp wav.prev wav.lst &&cp wav.now wav.prev");
			break;
			case KEY_F(9):
				refresh();
				system("cp wav.lst wav.now&&cp wav.nxt wav.lst&&cp wav.now wav.nxt");
			break;
			default:
		        getmaxyx(stdscr,yy,xx);	
			refresh();
			break;
		}
		menu(m,hl);
		if(choice!=0)
			break;
			
	}		
	clrtoeol();
	refresh();
		
return hl;
};

menu(WINDOW *c,int op){
	int i,y,x,xx,yy;
	
	getmaxyx(stdscr,yy,xx);
	i=y=3;
	for(x=0;x<7;++x){
		if(op==x+1){
			wattron(c,A_REVERSE);
			mvwprintw(c,y,24-(strlen(n[x].t)/2),"%s",n[x].t);
			mvwprintw(c,y,55-(strlen(n[x].a)/2),"%s",n[x].a);
			mvwprintw(c,y,22+((xx/2)-(strlen(n[x].al)/2)),"%s",n[x].al);
			mvwprintw(c,y,4,"%d)",x+1);
			mvwprintw(c,y,xx-15,"%d:%d",n[x].m,n[x].s);
			wattroff(c,A_REVERSE);
			}
		else{
			mvwprintw(c,y,24-(strlen(n[x].t)/2),"%s",n[x].t);
			mvwprintw(c,y,55-(strlen(n[x].a)/2),"%s",n[x].a);
			mvwprintw(c,y,22+((xx/2)-(strlen(n[x].al)/2)),"%s",n[x].al);
			mvwprintw(c,y,4,"%d)",x+1);
			mvwprintw(c,y,xx-15,"%d:%d",n[x].m,n[x].s);
			}
		++y;
		}
	wrefresh(c);
	
	}
#endif
