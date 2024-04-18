#include "../include/pieza.h"

struct rep_pieza {
    int id;
    char nombrePieza[MAX_NOMBRE_PIEZA];
    char nombreAutor[MAX_NOMBRE_AUTOR];
    char apellidoAutor[MAX_APELLIDO_AUTOR];
    TFecha fechaCreacion;
};

TPieza crearTPieza(int identificador, const char nombrePieza[MAX_NOMBRE_PIEZA], const char nombreAutor[MAX_NOMBRE_AUTOR], const char apellidoAutor[MAX_APELLIDO_AUTOR], TFecha fechaCreacion){

    TPieza pieza = new rep_pieza;
    pieza->id = identificador;
    strcpy(pieza->nombrePieza,nombrePieza);
    strcpy(pieza->nombreAutor,nombreAutor);
    strcpy(pieza->apellidoAutor,apellidoAutor);
    pieza->fechaCreacion = fechaCreacion;
    return pieza;
}

int idTPieza(TPieza pieza){ 
    return pieza->id;
}

void imprimirTPieza(TPieza pieza){
    printf("Pieza: %i\n", pieza->id);
    printf("%s-%s %s\n",pieza->nombrePieza,pieza->nombreAutor,pieza->apellidoAutor);
    printf("Creada en: ");
    imprimirTFecha(pieza->fechaCreacion);
}

void liberarTPieza(TPieza &pieza){
    liberarTFecha(pieza->fechaCreacion);
    delete pieza;
    pieza = NULL;
}


