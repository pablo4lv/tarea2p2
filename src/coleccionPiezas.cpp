#include "../include/coleccionPiezas.h"

struct rep_coleccionpiezas{
    TPieza pieza;
    TColeccionPiezas sig;
};

TColeccionPiezas crearColeccionPiezasVacia(){
    TColeccionPiezas coleccionPiezas = NULL;
    return coleccionPiezas; 
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
    if (coleccionPiezas!= NULL){
        while (coleccionPiezas->sig != NULL){
            imprimirTPieza(coleccionPiezas->pieza);
            coleccionPiezas = coleccionPiezas->sig;
        }
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
    TColeccionPiezas aux = coleccionPiezas->sig;
    while (aux != NULL){
        liberarTPieza(coleccionPiezas->pieza);
        delete coleccionPiezas;
        coleccionPiezas = aux;
        aux = aux->sig ;
    }
}