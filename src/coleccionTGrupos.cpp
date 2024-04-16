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
	nodo* actual = coleccion->primero;
	printf("Coleccion de grupos:\n");
	while (actual != NULL){
		printf("Grupo con edad promedio %.2f:\n", edadPromedioTGrupoABB(actual->grupo));
		imprimirTGrupoABB(actual->grupo);
		actual = actual->sig;
	}
}

void imprimirInvertidoTColeccionTGrupos(TColeccionTGrupos coleccion){
	nodo* actual = coleccion->ultimo;
	printf("Coleccion de grupos:\n");
	while (actual != NULL){
		printf("Grupo con edad promedio %.2f:\n", edadPromedioTGrupoABB(actual->grupo));
		imprimirTGrupoABB(actual->grupo);
		actual = actual->ant;
	}
}

nat cantidadTGruposColeccionTGrupos(TColeccionTGrupos coleccion){
	nat cant = 0;
	nodo* aux = coleccion->primero;
	while (aux != NULL){
		cant++;
		aux = aux->sig;
	}
	return cant;
}

TGrupoABB obtenerNesimoColeccionTGrupos(TColeccionTGrupos coleccion, int n){
	nodo* actual = coleccion->primero;
	int i = 1;
	while (actual != NULL && i < n){
		actual = actual->sig;
		i++;
	}
	if (i == n && actual != NULL){
		return actual->grupo;
	} else {
		return NULL;
	}
}

TGrupoABB obtenerPrimeroColeccionTGrupos(TColeccionTGrupos coleccion){
	return coleccion->primero->grupo;
}

TGrupoABB removerUltimoColeccionTGrupos(TColeccionTGrupos coleccion){
	TGrupoABB ultimo = coleccion->ultimo->grupo;
	if (coleccion->primero == coleccion->ultimo){
		delete coleccion->ultimo;
		coleccion->primero = NULL;
		coleccion->ultimo = NULL;
	} else {
		nodo* aux = coleccion->ultimo;
		coleccion->ultimo = coleccion->ultimo->ant;
		coleccion->ultimo->sig = NULL;
		delete aux;
	}
	return ultimo;
}

TGrupoABB removerNesimoColeccionTGrupos(TColeccionTGrupos coleccion, int n){
	TGrupoABB borrado;
	//Si el elem es el primero o el ultimo
	if (n == 1 || nat(n) == cantidadTGruposColeccionTGrupos(coleccion)){
		borrado = removerUltimoColeccionTGrupos(coleccion);
	} else {
		//Si no, esta entre dos elems
		nodo* aux = coleccion->primero;
		while(n > 1){
			n--;
			aux = aux->sig;
		}
		borrado = aux->grupo;
		aux->sig->ant = aux->ant;
		aux->ant->sig = aux->sig;
		delete aux;
	}
	return borrado;
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
