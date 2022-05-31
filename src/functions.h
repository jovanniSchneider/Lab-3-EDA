#ifndef TAREA_3_FUNCTIONS_H
#define TAREA_3_FUNCTIONS_H

#endif //TAREA_3_FUNCTIONS_H

#include "TDApueblo.h"


void leerArchivo(char * nombreArchivo,pueblo * village);

void leerArchivo(char *nombreArchivo, pueblo * village){
    FILE*pf;		   //para abrir archivo
    pf = fopen(nombreArchivo,"r");
    int cantidadVertices,i,j,k,w,cuartel;
    if (pf ==NULL){
        printf("Error de archivo\n");
    }else{
        //Cantidad de nodos y aristas
        fscanf(pf, "%d %d", &village->cantidadDeCuarteles,&cantidadVertices);
        village->grafo = crearGrafoVacio(cantidadVertices);
        village->cuarteles = crearListaVacia();
        for (int l = 0; l < village->cantidadDeCuarteles; ++l) {
            fscanf(pf,"%d",&cuartel);
            insertarInicio(village->cuarteles,cuartel);
        }
        //dependiendo de las lineas de archivo,
        // w es el peso (distancia) de la arista
        for(k=0;k<cantidadVertices;k++){
            fscanf(pf,"%d %d %d",&i, &j, &w);
            village->grafo->adyacencias[i-1][j-1] = w;
            village->grafo->adyacencias[j-1][i-1] = w;
        }
        fclose(pf);
    }
}
