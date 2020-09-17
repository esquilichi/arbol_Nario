#ifndef TELEMENTO_H
#define TELEMENTO_H
#include <stdio.h>
#include <string.h>

typedef struct TNombre{
     char nombre [128];

}TElemento;

void print (TElemento t);

void asignar(TElemento* copia, TElemento original);

int igual(TElemento* uno, TElemento* dos);

void crear(char* n, TElemento* e);

#endif


