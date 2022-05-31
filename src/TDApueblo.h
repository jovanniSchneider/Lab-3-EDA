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

void liberarPueblo(pueblo * village);

void liberarPueblo(pueblo *village) {
    liberarGrafo(village->grafo);
    liberarLista(village->cuarteles);
}

