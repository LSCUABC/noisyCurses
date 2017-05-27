#ifndef nplaying_h	
#define nplaying_h

#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "global.h"

int nplaying(int hl,cancion np, WINDOW *n, WINDOW *l){
	
	unsigned int t=time(0)+1;
	int ln,m,xx=0,yy=0,x=0,y=0;
	float uo;
	
	getmaxyx(stdscr,yy,xx);
	wrefresh(stdscr);
	
		mvwprintw(l,1,2,"-| Reproduciendo pista %d) |-            ",hl);
		wattron(l,A_REVERSE);
		mvwprintw(l,2,3,">>> %s - %s",np.t,np.a);
		wrefresh(l);
		switch(hl){
			case 1:
				system("aplay 1.wav 2>>log.txt &");
				mvprintw(4+hl,xx-18,"*");
			break;
			case 2:
				system("aplay 2.wav 2>>log.txt &");
				mvprintw(4+hl,xx-18,"*");
			break;
			case 3:
				system("aplay 3.wav 2>>log.txt &");
				mvprintw(4+hl,xx-18,"*");
			break;
			case 4:
				system("aplay 4.wav 2>>log.txt &");
				mvprintw(4+hl,xx-18,"*");
			break;
			case 5:
				system("aplay 5.wav 2>>log.txt &");
				mvprintw(4+hl,xx-18,"*");
			break;
			case 6:
	            		system("aplay 6.wav 2>>log.txt &");
                		mvprintw(4+hl,xx-18,"*");
			break;
			case 7:
                		system("aplay 7.wav 2>>log.txt &");
                		mvprintw(4+hl,xx-18,"*");
			break;
		}
		for(x=0;x<=np.m;x++){
		   for(y=0;y<60;y++){
			if(y>9)
				mvwprintw(n,2,8,"[0%d:%d]/[0%d:%d]",x,y,np.m,np.s);
			else
				mvwprintw(n,2,8,"[0%d:0%d]/[0%d:%d]",x,y,np.m,np.s);
			wattron(n,A_REVERSE);			
			mvwprintw(n,3,8,"[");
			mvwprintw(n,3,110,"]");
			wrefresh(n);
			
			ln=((np.m*60)+np.s);
			m=((x*60)+y);
			uo=((m*100)/ln)/1.00;
			
			mvwprintw(n,3,9+uo,"=");
			if(uo)
				mvwprintw(n,3,8+uo,"=");
				mvwprintw(n,3,111,"%.0f%%",uo);
			if(y<31)
				mvwprintw(n,4,8,"%s - %s",np.t,np.a);
			else
				mvwprintw(n,4,8,"    %s       ",np.al);
			
			wattroff(n,A_REVERSE);
			system("sleep 1");
			wrefresh(n);
			refresh();
			if(y==np.s&&x==np.m)
				break;
		}	
	  }
		
	return 0;
	
    };

#endif
