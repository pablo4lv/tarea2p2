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
    if (grupoABB == NULL){
        return;
    }
    if (idTVisitante(grupoABB->visitante) > idVisitante){
        removerTVisitanteTGrupoABB(grupoABB->izq,idVisitante);
    } else if (idTVisitante(grupoABB->visitante) < idVisitante) {
        removerTVisitanteTGrupoABB(grupoABB->der,idVisitante);
    } else {
        if (grupoABB->der == NULL){
            TGrupoABB aux = grupoABB;
            grupoABB = grupoABB->izq;
            liberarTVisitante(aux->visitante);
            delete aux;
        } else if(grupoABB->izq == NULL){
            TGrupoABB aux = grupoABB;
            grupoABB = grupoABB->der;
            liberarTVisitante(aux->visitante);
            delete aux;
        } else {
            TGrupoABB maxIzq = grupoABB->izq;
            while (maxIzq->der != NULL) {maxIzq = maxIzq->der;}
            //liberar grupoABB->visitante?
            liberarTVisitante(grupoABB->visitante);
            //copiar maxIzq en grupoABB?
            grupoABB->visitante = copiarTVisitante(maxIzq->visitante);
            removerTVisitanteTGrupoABB(grupoABB->izq, idTVisitante(maxIzq->visitante));
        }
    }
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

//aux
int sumaEdades(TGrupoABB grupoABB){
    if (grupoABB == NULL){
        return 0;
    } else {
        return (sumaEdades(grupoABB->izq) + sumaEdades(grupoABB->der) + edadTVisitante(grupoABB->visitante));
    }
}
//

float edadPromedioTGrupoABB(TGrupoABB grupoABB) {
    if (grupoABB != NULL){
        return sumaEdades(grupoABB)/cantidadVisitantesTGrupoABB(grupoABB);
    }else {
        return 0;
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

//
TGrupoABB Aplanar(TGrupoABB grupoABB, TGrupoABB &grupo2){
    if (grupoABB != NULL){
        if (grupoABB->izq == NULL && grupoABB->der == NULL){
            insertarTVisitanteTGrupoABB(grupo2,copiarTVisitante(grupoABB->visitante));
        }else{
            Aplanar(grupoABB->izq,grupo2);
            insertarTVisitanteTGrupoABB(grupo2,copiarTVisitante(grupoABB->visitante));
            Aplanar(grupoABB->der,grupo2);
        }
    }
    return grupo2;
}

TVisitante obtenerNesimoVisitanteTGrupoABB(TGrupoABB grupoABB, int n){
    TGrupoABB plano = NULL;
    Aplanar(grupoABB,plano);
    int i = 1;
    while (i < n){
        plano = plano->der;
        i++;
    }
    TVisitante salida = copiarTVisitante(plano->visitante);
    liberarTGrupoABB(plano);
    return salida;
}
