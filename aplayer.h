#ifndef aplayer_h
#define aplayer_h

#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "global.h"


int n_choices=6;
void menu(WINDOW *c,int op);
int aplayer(WINDOW *m){
		int hl=1,choice=0,xx,yy,c;	
		int ra=0;
		getmaxyx(stdscr,yy,xx);
		
		keypad(m,TRUE);
		noecho();
		cbreak();
		
		menu(m,hl);
		while(1){
		c=wgetch(m);
		
		switch(c){
			case KEY_UP:
				if(hl==1)
					hl=7;
				else
					--hl;
			break;
			
			case KEY_DOWN:
				if(hl==7)
					hl=1;
				else
					++hl;				
			break;
			
			case 10:
				choice=hl;
			break;
			
			case KEY_F(10):
				hl=rand()%8;
				choice=hl;
			break;
			
			default: refresh();
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
	i=y=2;
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
