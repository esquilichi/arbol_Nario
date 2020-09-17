
#include <stdio.h>
#include <stdlib.h>
#include "TNaryTree.h"


int main() {

    TNaryTree family;
    TElemento m36,m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11,m12,m13,m14,m15,m16,m17,m18,m19,m20,m21,m22,m23,m24,m25,m26,m27,m28,m29,m30,m31,m32,m33,m34,m35;
    
    crear("Alfonso", &m1);
    crear("Miguel", &m2);
    crear("Jeremias", &m3);
    crear("Susana", &m4);
    crear("Laura", &m5);
    crear("Simon", &m6);
    crear("Alberto", &m7);
    crear("Jesus", &m8);
    crear("Maria", &m9);
    crear("Pedro", &m10);
    crear("Iker", &m11);
    crear("Esther", &m12);
    crear("Guadalupe", &m13);
    crear("Emilio", &m14);
    crear("Ana", &m15);
    crear("Irene", &m16);
    crear("Felipe", &m17);
    crear("Lucia", &m18);
    crear("Andres", &m19);
    crear("Patricia", &m20);
    crear("Juan", &m21);
    crear("Roberto", &m22);
    crear("Cesar", &m23);
    crear("Silvia", &m24);
    crear("Gema", &m25);
    crear("Angel", &m26);
    crear("Luis", &m27);
    crear("Christian", &m28);
    crear("Daniel", &m29);
    crear("Joel", &m30);
    crear("Paloma", &m31);
    crear("Blanca", &m32);
    crear("Marcos", &m33);
    crear("Teresa", &m34);
    crear("Pepito", &m35);

    crearArbolVacio(&family);
    /////////////////////////////////////////////////////////////////////////////77
    //ALFONSO
    anadirRaiz(&family, m1);
     
    //HIJOS DE ALFONSO: MIGUEL, JEREMIAS, SUSANA, LAURA
    insertarHijo(&family, m1, m2);
    insertarHermano(&family, m2, m3);
    insertarHermano(&family, m3, m4);
    insertarHermano(&family, m4, m5);

    //HIJOS MIGUEL: SIMON
    insertarHijo(&family, m2, m6);
    
    //HIJOS JEREMIAS: ALBERTO, JESUS, MARIA
    insertarHijo(&family, m3, m7);
    insertarHijo(&family, m3, m8);
    insertarHijo(&family, m3, m9);

    //HIJOS SUSANA: PEDRO, IKER
    insertarHijo(&family, m4, m10);
    insertarHijo(&family, m4, m11);

    //HIJOS LAURA: ESTHER, GUADALUPE, EMILIO
    insertarHijo(&family, m5, m12);
    insertarHijo(&family, m5, m13);
    insertarHijo(&family, m5, m14);

    ///////////////////////////////////////////////////////////////////////////////

    ///////////////////////////NIETOS MIGUEL///////////////////////////////////////
    //HIJOS SIMON: ANA
    insertarHijo(&family, m6, m15);

    ///////////////////////////NIETOS JEREMIAS////////////////////////////////////
    //HIJOS ALBERTO: IRENE, FELIPE
    insertarHijo(&family, m7, m16);
    insertarHermano(&family, m16, m17);
    
    //HIJOS MARIA: LUCIA, ANDRES
    insertarHijo(&family, m9, m18);
    insertarHijo(&family, m9, m19);

    ///////////////////////////NIETOS SUSANA//////////////////////////////////////
    //HIJOS PEDRO: PATRICIA
    insertarHijo(&family, m10, m20);

    ///////////////////////////NIETOS LAURA////////////////////////////////////////
    //HIJOS ESTHER: JUAN, ROBERTO, CESAR, SILVIA
    insertarHijo(&family, m12, m21);
    insertarHijo(&family, m12, m22);
    insertarHijo(&family, m12, m23);
    insertarHijo(&family, m12, m24);

    ////////////////////////////////////////////////////////////////////////////////

    ///////////////////////////NIETOS ALBERTO///////////////////////////////////////
    //HIJOS IRENE: GEMA, ANGEL, LUIS
    insertarHijo(&family, m16, m25);
    insertarHermano(&family, m25, m26);
    insertarHermano(&family, m26, m27);

    ///////////////////////////NIETOS MARIA////////////////////////////////////////
    //HIJOS ANDRES: CHRISTIAN, DANIEL
    insertarHijo(&family, m19, m28);
    insertarHijo(&family, m19, m29);

    ///////////////////////////NIETOS PEDRO////////////////////////////////////////
    //HIJOS PATRICIA: JOEL
    insertarHijo(&family, m20, m30);

    ///////////////////////////NIETOS ESTHER////////////////////////////////////////
    //HIJOS ROBERTO: PALOMA, BLANCA, MARCOS
    insertarHijo(&family, m22, m31);
    insertarHijo(&family, m22, m32);
    insertarHermano(&family, m32, m33);

    //HIJOS SILVIA: TERESA
    insertarHijo(&family, m24, m34);

    

    ///////////////////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////
    

    
    //FAMILIA COMPLETA
    printf("La familia completa es:\n");
    TLinkedList familia;
    crearVacia(&familia);
    recorrido(family, &familia);
    mostrar(familia);
    printf("\n");

    //COPIAR
    
    TNaryTree fotocopia;
    TLinkedList copy;
    crearVacia(&copy);
    crearArbolVacio(&fotocopia);
    copiarArbol(family, &fotocopia);
    listaHijos(fotocopia, &copy, m7);
    printf("Los hijos de Alberto en el arbol copiado:\n");
    mostrar(copy);
    printf("El padre de Ana en el arbol copiado:\n");
    TElemento papi;
    parent(fotocopia, m15, &papi);

    //HAY ALGUIEN?
    esArbolVacio(family);
    printf("\n%i: HAY GENTE JEJE\n", esArbolVacio(family));

    //MIEMBROS
    numeroNodos(family);
    printf("Hay %i miembros\n", numeroNodos(family));
    
    //ULTIMAS GENERACIONES
    numeroHojas(family);
    printf("Hay %i hojas\n", numeroHojas(family));
    
    //CUANTAS GENERACIONES?
    printf("Hay %i generaciones\n", altura(family));
    //Si Teresa tuviera un hijo:
    insertarHijo(&family, m34, m35);
    printf("Hay %i generaciones al anadir a Pepito\n", altura(family));


    //ES HUERFANO?
    TElemento papa;
    printf("Su padre es: \n");
    parent(family, m1, &papa);

    //HIJOS
    TLinkedList hijitos;
    crearVacia(&hijitos);
    listaHijos(family, &hijitos, m2);
    printf("Sus hijos son:\n");
    mostrar(hijitos);
    
    //HERMANOS
    TLinkedList hermanitos;
    crearVacia(&hermanitos);
    listaHermanos(family, &hermanitos, m13);
    printf("Sus hermanos son:\n");
    mostrar(hermanitos);

    //ANTEPASADOS
    TLinkedList abuelitos;
    crearVacia(&abuelitos);
    listaAntepasados(family, &abuelitos, m13);
    printf("Sus antepasados son:\n");
    mostrar(abuelitos);

    //BORRAR
    printf("Borramos a 3 ninios:\n");
    borrarNodo(&family, m9);
    borrarNodo(&family, m19);
    borrarNodo(&family, m29);
    borrarNodo(&family, m35); //Borramos a Pepito para que salgan los resultados originales

    //Comprobamos que se han eliminado haciendo la lista de hijos
    numeroNodos(family);
    printf("Hay %i nodos\n", numeroNodos(family));
    TLinkedList hijos;
    crearVacia(&hijos);
    listaHijos(family, &hijos, m28);
    printf("Sus hijos son:\n");
    mostrar(hijos);
    printf("\n");

    //Comprobamos haciendo un recorrido que ya no estan esos hijos
    printf("El nuevo arbol seria:\n");
    recorrido(family, &familia);
    mostrar(familia);
  

    //DESAPARECEN
    borrarArbol(&family);
    numeroNodos(family);
    printf("Hay %i miembros\n", numeroNodos(family));

    


    return 0;


}