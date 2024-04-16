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
	nodo* nuevo = new nodo;
	nuevo->grupo = grupo;
	nuevo->sig = NULL;

	if (coleccion->primero == NULL){
		coleccion->primero = nuevo;
		coleccion->ultimo = nuevo;
		nuevo->ant = NULL;
	}else{
		while (edadPromedioTGrupoABB(coleccion->primero->grupo) <= edadPromedioTGrupoABB(grupo)){
			coleccion->primero = coleccion->primero->sig;
		}
		//CASO: insertar al inicio
		if (coleccion->primero->ant == NULL){
			coleccion->primero->ant = nuevo;
			nuevo->sig = coleccion->primero;
			coleccion->primero = nuevo;
		} else if (coleccion->primero == NULL){
			//CASO: insertar al final
			coleccion->ultimo->sig = nuevo;
			nuevo->ant = coleccion->ultimo;
			coleccion->ultimo = nuevo;
		}else {
			//CASO: insertar entre dos elementos
			coleccion->primero->ant->sig = nuevo;
			nuevo->ant = coleccion->primero->ant;
			coleccion->primero->ant = nuevo;
			nuevo->sig = coleccion->primero;
		}
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
