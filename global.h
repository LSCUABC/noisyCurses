#ifndef global_h
#define global_h

#include <time.h>
#include <ncurses.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
 
//cancion setCancion();
//void guardarCancion(cancion,char []);
//void choices(WINDOW *m, int hl,cancion n[]);


typedef struct {
    char t[50];
    char a[50];
    char al[50];		
    int s;
    int m;
} cancion;

cancion n[7];

int fexists(char archivo[]){
	      
	FILE *f = fopen(archivo, "r");
          if(f != NULL){
                    fclose(f);
                            return 1;
                                }
     
    return 0;
};


 
#endif
