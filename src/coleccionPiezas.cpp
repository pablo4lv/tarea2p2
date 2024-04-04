#include "../include/coleccionPiezas.h"

struct rep_coleccionpiezas{
    TPieza pieza;
    TColeccionPiezas sig;
};

TColeccionPiezas crearColeccionPiezasVacia(){
    return NULL;
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
        nuevo->pieza = pieza;
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
    return piezas == NULL;
}

bool existePiezaColeccionPiezas(TColeccionPiezas coleccionPiezas, int idPieza){
    while (coleccionPiezas != NULL){
        if (idTPieza(coleccionPiezas->pieza) == idPieza){
            return true;
        };
        coleccionPiezas = coleccionPiezas->sig;
    }
    return false;
}

TPieza obtenerPiezaColeccionPiezas(TColeccionPiezas coleccionPiezas, int idPieza){
    if (existePiezaColeccionPiezas(coleccionPiezas, idPieza)){
        while(idTPieza(coleccionPiezas->pieza) != idPieza){
            coleccionPiezas = coleccionPiezas->sig;
        }
    }
    return coleccionPiezas->pieza;
}

void removerPiezaColeccionPiezas(TColeccionPiezas &coleccionPiezas, int idPieza){
    if (existePiezaColeccionPiezas(coleccionPiezas, idPieza)){
        TColeccionPiezas aux;
        if (idTPieza(coleccionPiezas->pieza) == idPieza){
            aux = coleccionPiezas->sig;
            liberarTPieza(coleccionPiezas->pieza);
            delete coleccionPiezas;
            coleccionPiezas = aux;
        } else {
            aux = coleccionPiezas;
            while (idTPieza(aux->sig->pieza) != idPieza){
                aux = aux->sig;
            }
            TColeccionPiezas aux2 = aux->sig->sig;
            liberarTPieza(aux->sig->pieza);
            delete aux->sig;
            aux->sig = aux2;
        }
    }
}

void liberarColeccionPiezas(TColeccionPiezas &coleccionPiezas){
    if (coleccionPiezas != NULL){
        TColeccionPiezas aux;
        while (coleccionPiezas != NULL){
            aux = coleccionPiezas;
            coleccionPiezas = coleccionPiezas->sig;
            liberarTPieza(aux->pieza);
            delete aux;
        }
    }
}