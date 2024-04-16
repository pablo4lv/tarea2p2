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

	//Insertar en col vacía
	if (coleccion->primero == NULL){
		coleccion->primero = nuevo;
		coleccion->ultimo = nuevo;
		nuevo->ant = NULL;
	} else {
		nodo* actual = coleccion->primero;
		while (actual != NULL && edadPromedioTGrupoABB(actual->grupo) <= edadPromedioTGrupoABB(grupo)){
			actual = actual->sig;
		}

		//CASO: insertar al final
		if (actual == NULL){
			coleccion->ultimo->sig = nuevo;
			nuevo->ant = coleccion->ultimo;
			coleccion->ultimo = nuevo;
		} else if (actual->ant == NULL){
			//CASO: insertar al inicio
			nuevo->sig = actual;
			actual->ant = nuevo;
			coleccion->primero = nuevo;
		}else {
			//CASO: insertar entre dos elementos
			nuevo->sig = actual;
			nuevo->ant = actual->ant;
			actual->ant->sig = nuevo;
			actual->ant = nuevo;
		}

		// //CASO: insertar al inicio
		// if (actual->ant == NULL){
		// 	nuevo->sig = actual;
		// 	actual->ant = nuevo;
		// 	coleccion->primero = nuevo;
		// } else if (actual == NULL){
		// 	//CASO: insertar al final
		// 	coleccion->ultimo->sig = nuevo;
		// 	nuevo->ant = coleccion->ultimo;
		// 	coleccion->ultimo = nuevo;
		// }else {
		// 	//CASO: insertar entre dos elementos
		// 	nuevo->sig = actual;
		// 	nuevo->ant = actual->ant;
		// 	actual->ant->sig = nuevo;
		// 	actual->ant = nuevo;
		// }
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
	nodo* aux;
	while (coleccion->primero != NULL){
		aux = coleccion->primero;
		coleccion->primero = coleccion->primero->sig;
		liberarTGrupoABB(aux->grupo);
		delete aux;
		aux = NULL;
	}
	delete coleccion;
	coleccion = NULL;
}

TGrupoABB obtenerVisitantesRepetidos(TColeccionTGrupos coleccion){
	return NULL;
}

TVisitante visitanteMasRepetido(TColeccionTGrupos coleccion){
	return NULL;
}
