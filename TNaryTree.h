#include <stdio.h>
#include <stdlib.h>
#include "TElemento.h"
#include "simplelinkedlist.h"

typedef struct NodeTree{
        TElemento info;
        struct NodeTree* padre;
        struct NodeTree* hijo;
        struct NodeTree* hermano;

    }TNodeTree;

typedef TNodeTree* TNaryTree;


void crearArbolVacio (TNaryTree* Arbol);
void anadirRaiz (TNaryTree* Arbol, TElemento i); 
void insertarHijo (TNaryTree* Arbol, TElemento i1, TElemento i2);
void insertarHermano (TNaryTree* Arbol, TElemento i1, TElemento i2);
void borrarArbol (TNaryTree* Arbol);
void copiarArbol (TNaryTree original, TNaryTree* copia);
int esArbolVacio (TNaryTree Arbol);
int numeroNodos (TNaryTree Arbol);
int numeroHojas (TNaryTree Arbol);
int altura (TNaryTree Arbol);
void parent (TNaryTree Arbol, TElemento i1, TElemento* i2);
void listaHijos (TNaryTree Arbol, TLinkedList* l, TElemento i);
void listaHermanos (TNaryTree Arbol, TLinkedList* l, TElemento i);
void listaAntepasados (TNaryTree Arbol, TLinkedList* l, TElemento i);
void recorrido (TNaryTree Arbol, TLinkedList* l);
void borrarNodo (TNaryTree* Arbol, TElemento i);


