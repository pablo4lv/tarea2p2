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
    } else {
        if (idTVisitante(visitante) < idTVisitante(grupoABB->visitante)){
            insertarTVisitanteTGrupoABB(grupoABB->izq,visitante);
        } else {
            insertarTVisitanteTGrupoABB(grupoABB->der,visitante);
        }
    }
}

void imprimirTGrupoABB(TGrupoABB grupoABB){
    // if (grupoABB != NULL){
    //     imprimirTGrupoABB(grupoABB->izq);
    //     imprimirTVisitante(grupoABB->visitante);
    //     imprimirTGrupoABB(grupoABB->der);
    // }
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
    return false;
}

TVisitante obtenerTVisitanteTGrupoABB(TGrupoABB grupoABB, int idVisitante){
    return NULL;
}

void removerTVisitanteTGrupoABB(TGrupoABB &grupoABB, int idVisitante){
    
}

nat alturaTGrupoABB(TGrupoABB grupoABB) {
    return 0;
}

int cantidadVisitantesTGrupoABB(TGrupoABB grupoABB){
    return 0;
}

float edadPromedioTGrupoABB(TGrupoABB grupoABB) {
    return 0.;
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
        }
    }
}

TVisitante maxIdTVisitanteTGrupoABB(TGrupoABB grupoABB){
    return NULL;
}

TVisitante obtenerNesimoVisitanteTGrupoABB(TGrupoABB grupoABB, int n){
    return NULL;
}

