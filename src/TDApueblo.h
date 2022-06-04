//Macros
#ifndef TAREA_3_TDAPUEBLO_H
#define TAREA_3_TDAPUEBLO_H

#endif //TAREA_3_TDAPUEBLO_H
#include "TDAgrafo.h"


typedef struct pueblo{
    int cantidadDeCuarteles;
    TDAlista * cuarteles;
    TDAgrafo * grafo;
}pueblo;


pueblo * crearPuebloVacio();
void liberarPueblo(pueblo * village);

pueblo * crearPuebloVacio(){
    pueblo * village = (pueblo*) malloc(sizeof (pueblo));
    village->cuarteles = crearListaVacia();
    return village;
}

void liberarPueblo(pueblo *village) {
    liberarGrafo(village->grafo);
    liberarLista(village->cuarteles);
}