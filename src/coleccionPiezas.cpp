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
    
}

void imprimirColeccionPiezas(TColeccionPiezas coleccionPiezas){
   
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
    
}