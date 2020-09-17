#include <stdio.h>
#include <string.h>
#include "TElemento.h"

void print (TElemento t){
    printf("\t%s\n",t.nombre);
    
}

void asignar(TElemento* copia, TElemento original){
    strcpy((*copia).nombre,original.nombre);
}

int igual(TElemento* uno, TElemento* dos){
    return  ((strcmp((*uno).nombre,dos->nombre)==0));
}


void crear(char* n, TElemento* e){
    strcpy(e->nombre,n);
}


