#include <stdio.h>
#include <stdlib.h>
#include "TNaryTree.h"
#include "cola.h"


void EncontrarArbol (TNaryTree Arbol, TElemento i, TNaryTree* found) {
    if (Arbol==NULL){
        *found=NULL;
    }else {
        if (igual(&i, &(Arbol)->info)) {
            *found=Arbol;
        }else {
            TNaryTree provisional;
            TNaryTree recorredorAuxiliar = Arbol->hijo;
            int founded=0;
            *found=NULL;
            while ((recorredorAuxiliar!=NULL) && (!founded)) {
                EncontrarArbol(recorredorAuxiliar, i, &provisional);
                if(provisional!=NULL) {
                    *found=provisional;
                    founded=1;
                }else {
                    recorredorAuxiliar = recorredorAuxiliar->hermano;
                }
            }       
        }  
    }
}

void crearArbolVacio (TNaryTree* Arbol) {
    *Arbol = NULL;
}


void anadirRaiz (TNaryTree* Arbol, TElemento i) {
    if(esArbolVacio(*Arbol)) {
        TNaryTree aux = (TNaryTree) malloc(sizeof(TNodeTree));
        aux->padre = NULL;
        aux->hermano = NULL;
        aux->hijo = NULL;
        asignar(&aux->info, i);
        *Arbol = aux;
    }
}


void insertarHijo (TNaryTree* Arbol, TElemento i1, TElemento i2) {
    if(!esArbolVacio(*Arbol)) {
        TNaryTree papa;
        TNaryTree bebe = (TNaryTree)malloc(sizeof(TNodeTree));
        EncontrarArbol(*Arbol, i1, &papa);
        if(papa != NULL ) {
            TNaryTree auxiliar = papa->hijo;
            if (auxiliar == NULL) {
                bebe->padre = papa;
                bebe->hermano = NULL;
                bebe->hijo = NULL;
                papa->hijo = bebe;
                asignar(&bebe->info ,i2);
            }else {
                while (auxiliar->hermano != NULL) {
                    auxiliar= auxiliar->hermano;
                }
                auxiliar->hermano = bebe;
                bebe->padre = papa;
                bebe->hermano = NULL;
                bebe->hijo = NULL;

                asignar(&bebe->info ,i2);
            }
        }
    }
}


void insertarHermano (TNaryTree* Arbol, TElemento i1, TElemento i2) {
    TNaryTree hermanitoMayor;
    EncontrarArbol(*Arbol, i1, &hermanitoMayor);
    if(hermanitoMayor != NULL) {        
        TNaryTree hermanitoMenor = (TNaryTree)malloc(sizeof(TNodeTree));
        TNaryTree recorredor;
                
        if(hermanitoMayor->hermano==NULL) {
            hermanitoMayor->hermano = hermanitoMenor;
        }else {
            recorredor= hermanitoMayor;
            while (recorredor->hermano!=NULL) {
                recorredor= recorredor->hermano;
            }
            recorredor->hermano = hermanitoMenor;
        }     
        asignar(&(hermanitoMenor)->info, i2);
        hermanitoMenor->padre = hermanitoMayor->padre;
        hermanitoMenor->hijo = NULL;
        hermanitoMenor->hermano = NULL;
    }
}


void borrarArbol (TNaryTree* Arbol) {
    if(!esArbolVacio(*Arbol)) {
        borrarArbol(&((*Arbol)->hijo));
        borrarArbol(&((*Arbol)->hermano));
        free (*Arbol);
        *Arbol = NULL;
    }
}


void enlazarPadre (TNaryTree original, TNaryTree* copia) {
    TNaryTree aux1, aux2, aux3, aux4;

    if(!esArbolVacio(original)) {
        aux1 = original;
        aux2 = *copia;
        EncontrarArbol(*copia, aux1->info, &aux2);
        aux3 = aux1->padre;
        if (aux3 != NULL) {
            EncontrarArbol(*copia, aux3->info, &aux4);
            aux2->padre = aux4;
        }
        enlazarPadre(original->hijo, copia);
        enlazarPadre(original->hermano, copia);
    }
}


void copiarArbolAux (TNaryTree original, TNaryTree* copia) {
    if(original==NULL) {
        crearArbolVacio(copia);
    }else {
        TNaryTree son, bro;
        copiarArbolAux(original->hermano, &bro);
        copiarArbolAux(original->hijo, &son);
        TNaryTree reserva = (TNaryTree)malloc(sizeof(TNodeTree));
        reserva->hermano = bro;
        reserva->hijo = son;
        asignar(&reserva->info, original->info);
        *copia = reserva;  
    }
}

void copiarArbol(TNaryTree original, TNaryTree* copia) {
    copiarArbolAux(original, copia);
    enlazarPadre(original, copia);
}


int esArbolVacio (TNaryTree Arbol) {
    if (Arbol==NULL) {
        return 1;
    }else {
        return 0;
    }
}


int numeroNodos (TNaryTree Arbol) {
    if (esArbolVacio(Arbol)) {
        return 0;
    }else {
        return 1 +  numeroNodos(Arbol->hermano) + numeroNodos(Arbol->hijo);
    }
}



int numeroHojas (TNaryTree Arbol) {
    if (esArbolVacio(Arbol)) {
        return 0;
    }else if (((Arbol->hermano)==NULL) && ((Arbol->hijo)==NULL)) {
        return 1;
    }else if (((Arbol->hijo)==NULL) && (Arbol->hermano != NULL)) {
        return 1 + numeroHojas(Arbol->hermano); 
    }else {
        return numeroHojas(Arbol->hermano) + numeroHojas(Arbol->hijo);
    }
}



int altura (TNaryTree Arbol) {
    if(esArbolVacio(Arbol)) {
        return 0;
    }else {
        int niveles = 0;
        TNaryTree ayuda = Arbol->hijo;
        int cont = 0;
        while (ayuda != NULL) {
            cont = altura(ayuda);
            if(cont > niveles) {
                niveles = cont;
            }
            ayuda = ayuda->hermano;
        }
        return 1 + niveles;
    }    
}




void parent (TNaryTree Arbol, TElemento i1, TElemento* i2) {
    TNaryTree criatura;
    EncontrarArbol(Arbol, i1, &criatura);
    
    if(criatura->padre == NULL) {
        i2 = NULL;
        printf(":-(\n");
    }else {
        asignar(i2, criatura->padre->info);
        print(*i2);
    }
}




void listaHijos (TNaryTree Arbol, TLinkedList* l, TElemento i) {
    TNaryTree progenitor, auxiliar;
    TLinkedList hijos;
    crearVacia(&hijos);
    EncontrarArbol(Arbol, i, &progenitor);
    auxiliar= progenitor->hijo;
    TElemento aus;
    
    while(auxiliar!=NULL) {
        asignar(&aus, auxiliar->info);
        insertarFinal(aus, &hijos);
        auxiliar = auxiliar->hermano;
    }
    
    copiar(hijos, l);
}



void listaHermanos (TNaryTree Arbol, TLinkedList* l, TElemento i) {
    TNaryTree hermanoEncontrado, auxiliar;
    TLinkedList hermanos;
    crearVacia(&hermanos);
    EncontrarArbol(Arbol, i, &hermanoEncontrado);
    auxiliar= hermanoEncontrado->padre;
    auxiliar= auxiliar->hijo;
    TElemento aus;

    while (auxiliar != NULL) {
        if (!igual(&auxiliar->info, &hermanoEncontrado->info)) {
            asignar(&aus, auxiliar->info);
            insertarFinal(aus, &hermanos);    
        }
        auxiliar= auxiliar->hermano;
    }
    
    copiar(hermanos, l);
}


void listaAntepasados (TNaryTree Arbol, TLinkedList* l, TElemento i) {
    TNaryTree primerPadre, ayuda;
    TLinkedList antepasados;
    crearVacia(&antepasados);
    EncontrarArbol(Arbol, i, &primerPadre);
    TElemento aus;
    ayuda = primerPadre->padre;
    
    while (ayuda != NULL) {
        asignar(&aus, ayuda->info);
        insertar(aus, &antepasados);
        ayuda = ayuda->padre;
    }
    
    copiar(antepasados, l);
}



void recorrido (TNaryTree Arbol, TLinkedList* l) {
    if(!esArbolVacio(Arbol)) {
        Cola familia;
        crearColaVacia(&familia);
        crearVacia(l);
        TNaryTree aus = Arbol;
        TElemento cabesa, aux;
        asignar(&cabesa, aus->info);
        insertarCola(&familia, cabesa);

        while (!esColaVacia(familia)) {
            aus= aus->hijo;
            while(aus != NULL) {
                asignar(&cabesa, aus->info);
                insertarCola(&familia, cabesa);
                aus= aus->hermano;
            }
            primeroCola(familia, &aux);
            insertarFinal(aux, l);
            eliminarCola(&familia);
            primeroCola(familia, &aux);
            EncontrarArbol(Arbol, aux, &aus);    
        } 

    }else {
        crearVacia(l);
    }
}



void borrarNodo (TNaryTree* Arbol, TElemento i) {
    if(!esArbolVacio(*Arbol)) {
        TNaryTree fuera, p, h;
        EncontrarArbol(*Arbol, i, &fuera);
        p = fuera->hijo;
        h = fuera->hermano;
        //Caso 1: SI tiene hijos
        if (p != NULL) {
            asignar(&fuera->info, p->info);
            borrarNodo(&p, p->info);
        }
        //Caso 2: NO tiene hijos SI tiene hermanos
        else if((p == NULL) && (h != NULL)) {
           
            if((h != NULL) && (fuera->padre->hijo != fuera)) {
                TNaryTree aux = fuera->padre;
                TNaryTree aux2 = aux->hijo;
                int f = 0;
                while (aux2 != NULL && !f) {
                    if(igual(&aux2->hermano->info, &fuera->info)) {
                        aux2->hermano = fuera->hermano;
                        f=1; 
                    }else{
                        aux2 = aux2->hermano;
                    }
                }
                free(fuera);
            }
            //Si es el primer hijo
            else {
                fuera->padre->hijo = fuera->hermano;
                free(fuera);
            }            
            
        }
        //Caso 3: NO tiene hijos NO tiene hermanos
        else if((p == NULL) && (h == NULL)) {
            //Caso 3.1: hijo unico
            if(fuera->padre->hijo == fuera) {
                fuera->padre->hijo = NULL;
                free(fuera);
            }
            //Caso 3.2: ultimo de los hermanos
            else {
                TNaryTree aux = fuera->padre->hijo;
                while(aux != fuera) {
                    aux = aux->hermano;
                }
                aux->hermano = NULL;
                free(fuera);
            }
        }
    }
}


