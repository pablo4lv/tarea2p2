#include "../include/visitante.h"

struct rep_visitante {
    int id;
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO];
    int edad;
};

TVisitante crearTVisitante(int id, const char nombre[MAX_NOMBRE], const char apellido[MAX_APELLIDO], int edad){
    TVisitante visitante = new rep_visitante;
    visitante->id = id;
    strcpy(visitante->nombre,nombre);
    strcpy(visitante->apellido,apellido);
    visitante->edad = edad;
    return visitante; 
}

void nombreTVisitante(TVisitante visitante, char nombre[MAX_NOMBRE]){

}

void apellidoTVisitante(TVisitante visitante, char apellido[MAX_APELLIDO]){

}

int idTVisitante(TVisitante visitante){
    return 0;
}

int edadTVisitante(TVisitante visitante){
    return 0;
}

void liberarTVisitante(TVisitante &visitante){
    delete visitante;
    visitante = NULL;
}

TVisitante copiarTVisitante(TVisitante visitante){
    return NULL;
}

void imprimirTVisitante(TVisitante visitante){
    printf("Visitante %s %s\n", visitante->nombre, visitante->apellido);
    printf("Id: %i\n", visitante->id);
    printf("Edad: %i\n", visitante->edad);
}

