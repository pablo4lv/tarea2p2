#include "../include/coleccionTGrupos.h"

struct nodo{
	TGrupoABB grupo;
	nodo* sig;
	nodo* ant;
};
struct rep_coleccionTGrupos {
	nodo* primero;
	nodo* ultimo;
};


TColeccionTGrupos crearTColeccionTGruposVacia(){
	TColeccionTGrupos vacia = new rep_coleccionTGrupos;
	vacia->primero = NULL;
	vacia->ultimo = NULL;
	return vacia;
}

void insertarGrupoTColeccionTGrupos(TColeccionTGrupos coleccion, TGrupoABB grupo){
	if (coleccion->primero == NULL){
		coleccion->primero = new nodo;
		coleccion->primero->grupo = grupo;
		coleccion->ultimo = coleccion->primero;
	}else{

	}
}

void imprimirTColeccionTGrupos(TColeccionTGrupos coleccion){

}

void imprimirInvertidoTColeccionTGrupos(TColeccionTGrupos coleccion){

}

nat cantidadTGruposColeccionTGrupos(TColeccionTGrupos coleccion){
	return 0;
}

TGrupoABB obtenerNesimoColeccionTGrupos(TColeccionTGrupos coleccion, int n){
	return NULL;
}

TGrupoABB obtenerPrimeroColeccionTGrupos(TColeccionTGrupos coleccion){
	return NULL;
}

TGrupoABB removerUltimoColeccionTGrupos(TColeccionTGrupos coleccion){
	return NULL;
}

TGrupoABB removerNesimoColeccionTGrupos(TColeccionTGrupos coleccion, int n){
	return NULL;
}

void liberarTColeccionTGrupos(TColeccionTGrupos &coleccion){
	
}

TGrupoABB obtenerVisitantesRepetidos(TColeccionTGrupos coleccion){
	return NULL;
}

TVisitante visitanteMasRepetido(TColeccionTGrupos coleccion){
	return NULL;
}
