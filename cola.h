#ifndef cola_h
#define cola_h
#include <stdlib.h>
#include "TElemento.h"


struct NodoCola {
    TElemento info;
    struct NodoCola *sig;
};

typedef struct NodoCola Nodo;

struct Cola {
    Nodo* ultimo;
};

typedef struct Cola Cola;

void crearColaVacia (Cola* cola);
void insertarCola (Cola* cola, TElemento e);
int esColaVacia (Cola cola);
void primeroCola(Cola cola, TElemento* e);
void eliminarCola (Cola* cola);
void mostrarCola (Cola cola);
int size(Cola cola);

#endif 
