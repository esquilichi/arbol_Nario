#include "cola.h"


void crearColaVacia (Cola* cola) {
    cola->ultimo=NULL;
}
void insertarCola (Cola* cola, TElemento e) {
    Nodo* nuevo = (Nodo*) malloc (sizeof (Nodo));
    asignar (&(nuevo->info), e);

    if (esColaVacia (*cola)) {
        nuevo->sig=nuevo;
    }else{
        nuevo->sig = cola->ultimo->sig;
        cola->ultimo->sig = nuevo;
    }
    cola->ultimo=nuevo;


}
int esColaVacia (Cola cola){
    return (cola.ultimo==NULL);
}


void primeroCola (Cola cola, TElemento* e) {
    if (!esColaVacia(cola))
    {
        asignar(e, cola.ultimo->sig->info);
    }
}

void eliminarCola (Cola* cola) {
    Nodo *toRemove;
    if (cola->ultimo!=NULL) {
        toRemove = cola->ultimo->sig;

        if (cola->ultimo->sig==cola->ultimo) { 
            cola->ultimo=NULL;
        }else {
            cola->ultimo->sig= cola->ultimo->sig->sig;
        }
        free (toRemove);
    }
   
}
void mostrarCola (Cola cola) {
    Nodo *limitador = cola.ultimo;
    Nodo *paux;

    if (esColaVacia (cola)) {
        printf ("Cola vacia\n");
    }else {
        printf ("[ ");
        paux = cola.ultimo->sig;
        while (paux!=limitador) {
            print (paux->info);
            printf (" ");
            paux=paux->sig;
        }
        print (paux->info);
        printf ("]\n");
    }
}

int size(Cola cola){
    if (esColaVacia (cola)) {
        return 0;
    }else {
        Nodo *limite = cola.ultimo;
        Nodo *paux;
        int contador = 0;
        paux = cola.ultimo->sig;
        while (paux!=limite) {
            paux = paux->sig;
            contador++;
        }
        return contador + 1;
    }
}