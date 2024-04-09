#include "../include/grupoABB.h"

struct rep_grupoABB {
    TVisitante visitante;
    TGrupoABB izq;
    TGrupoABB der;
};

TGrupoABB crearTGrupoABBVacio(){
    return NULL;
}

void insertarTVisitanteTGrupoABB(TGrupoABB &grupoABB, TVisitante visitante){
    // if (!existeTVisitanteTGrupoABB(grupoABB, idTVisitante(visitante))){

    // }
    if (grupoABB == NULL){
        TGrupoABB nuevo = new rep_grupoABB;
        nuevo->visitante = visitante;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        grupoABB = nuevo;
    } else {
        if (idTVisitante(visitante) < idTVisitante(grupoABB->visitante)){
            insertarTVisitanteTGrupoABB(grupoABB->izq,visitante);
        } else {
            insertarTVisitanteTGrupoABB(grupoABB->der,visitante);
        }
    }
}

void imprimirTGrupoABB(TGrupoABB grupoABB){
    if (grupoABB != NULL){
        if (grupoABB->izq == NULL && grupoABB->der == NULL){
            imprimirTVisitante(grupoABB->visitante);
        }else{
            imprimirTGrupoABB(grupoABB->izq);
            imprimirTVisitante(grupoABB->visitante);
            imprimirTGrupoABB(grupoABB->der);
        }
    }
}

bool existeTVisitanteTGrupoABB(TGrupoABB grupoABB, int idVisitante){
    while (grupoABB != NULL && idTVisitante(grupoABB->visitante) != idVisitante){
        if (idTVisitante(grupoABB->visitante) > idVisitante){
            grupoABB = grupoABB->izq;
        } else {
            grupoABB = grupoABB->der;
        }
    }
    return (grupoABB != NULL && idTVisitante(grupoABB->visitante) == idVisitante);
}

TVisitante obtenerTVisitanteTGrupoABB(TGrupoABB grupoABB, int idVisitante){
    while (grupoABB != NULL && idTVisitante(grupoABB->visitante) != idVisitante){
        if (idTVisitante(grupoABB->visitante) > idVisitante){
            grupoABB = grupoABB->izq;
        } else {
            grupoABB = grupoABB->der;
        }
    }
    return grupoABB->visitante;
}

void removerTVisitanteTGrupoABB(TGrupoABB &grupoABB, int idVisitante){
    
}

nat alturaTGrupoABB(TGrupoABB grupoABB) {
    if (grupoABB != NULL){
        return 1 + ((alturaTGrupoABB(grupoABB->izq) > alturaTGrupoABB(grupoABB->der)) ? alturaTGrupoABB(grupoABB->izq) : alturaTGrupoABB(grupoABB->der));
    } else {
        return 0;
    }
}

int cantidadVisitantesTGrupoABB(TGrupoABB grupoABB){
    if (grupoABB == NULL){
        return 0;
    } else {
        return 1 + (cantidadVisitantesTGrupoABB(grupoABB->izq) + cantidadVisitantesTGrupoABB(grupoABB->der));
    }
}

float edadPromedioTGrupoABB(TGrupoABB grupoABB) {
    if (grupoABB == NULL){
        return 0;
    } else {
        return (edadPromedioTGrupoABB(grupoABB->izq) + edadPromedioTGrupoABB(grupoABB->der) + edadTVisitante(grupoABB->visitante)/cantidadVisitantesTGrupoABB(grupoABB));
    }
}

void liberarNodo(TGrupoABB &grupoABB){
    liberarTVisitante(grupoABB->visitante);
    delete grupoABB;
    grupoABB = NULL;
}

void liberarTGrupoABB(TGrupoABB &grupoABB){
    if (grupoABB != NULL){
        if (grupoABB->izq == NULL && grupoABB->der == NULL){
            liberarNodo(grupoABB);
        } else {
            liberarTGrupoABB(grupoABB->izq);
            liberarTGrupoABB(grupoABB->der);
            liberarNodo(grupoABB);
        }
    }
}

TVisitante maxIdTVisitanteTGrupoABB(TGrupoABB grupoABB){
    while (grupoABB->der != NULL){
        grupoABB = grupoABB->der;
    }
    return grupoABB->visitante;
}

TVisitante obtenerNesimoVisitanteTGrupoABB(TGrupoABB grupoABB, int n){
    return NULL;
}

