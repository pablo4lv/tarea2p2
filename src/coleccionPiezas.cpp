#include "../include/coleccionPiezas.h"

struct rep_coleccionpiezas{
    TPieza pieza;
    TColeccionPiezas sig;
};

TColeccionPiezas crearColeccionPiezasVacia(){
    return nullptr;
}

void insertarPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, TPieza pieza){
    TColeccionPiezas nuevo = new rep_coleccionpiezas;

    if(coleccionPiezas == NULL){
        nuevo->pieza = pieza;
        nuevo->sig = NULL;
        coleccionPiezas = nuevo;
    }else if(idTPieza(pieza) < idTPieza(coleccionPiezas->pieza)){
        nuevo->pieza = pieza;
        nuevo->sig = coleccionPiezas;
        coleccionPiezas = nuevo;        
    }else{
        TColeccionPiezas aux = coleccionPiezas;
        int id = idTPieza(pieza);
        while ((aux->sig != NULL) && idTPieza(aux->sig->pieza) < id){
            aux = aux->sig;
        }
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }
}

void imprimirColeccionPiezas(TColeccionPiezas coleccionPiezas){
    while (coleccionPiezas != NULL){
        imprimirTPieza(coleccionPiezas->pieza);
        coleccionPiezas = coleccionPiezas->sig;
    }
}

bool esVaciaColeccionPiezas(TColeccionPiezas piezas){
    return true;
}

bool existePiezaColeccionPiezas(TColeccionPiezas coleccionPiezas, int idPieza){
    return true;
}

TPieza obtenerPiezaColeccionPiezas(TColeccionPiezas coleccionPiezas, int idPieza){
    return NULL;
}

void removerPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, int idPieza){
   
}

void liberarColeccionPiezas(TColeccionPiezas &coleccionPiezas){
    if (coleccionPiezas != NULL){
        TColeccionPiezas aux = coleccionPiezas;
        while (coleccionPiezas != NULL){
            coleccionPiezas = coleccionPiezas->sig;
            liberarTPieza(aux->pieza);
            delete aux;
        }
    }
}