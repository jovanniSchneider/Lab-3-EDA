#ifndef TAREA_3_FUNCTIONS_H
#define TAREA_3_FUNCTIONS_H

#endif //TAREA_3_FUNCTIONS_H

#include "TDApueblo.h"


void leerArchivo(char * nombreArchivo,pueblo * village);
void saltarLineasArchivo(FILE * archivo,int cantidadLineas);
int encontrarCantidadVertices(FILE * ,int cantLineas);

void leerArchivo(char *nombreArchivo, pueblo * village){
    FILE*pf;		   //para abrir archivo
    pf = fopen(nombreArchivo,"r");
    int cantidadAristas,cantidadVertices,i,j,k,w,cuartel,saltoDeLineas;
    if (pf ==NULL){
        printf("Error de archivo\n");
    }else{
        //Cantidad de cuarteles y aristas
        fscanf(pf, "%d %d", &village->cantidadDeCuarteles,&cantidadAristas);
        village->cuarteles = crearListaVacia();
        for (int l = 0; l < village->cantidadDeCuarteles; ++l) {
            fscanf(pf,"%d",&cuartel);
            insertarInicio(village->cuarteles,cuartel);
        }
        printf("flag\n");
        cantidadVertices = encontrarCantidadVertices(pf,cantidadAristas);
        printf("%d\n",cantidadVertices);
        village->grafo = crearGrafoVacio(cantidadVertices);
        saltoDeLineas = village->cantidadDeCuarteles + 2;
        printf("salto de lineas = %d\n",saltoDeLineas);
        saltarLineasArchivo(pf,saltoDeLineas);
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

void saltarLineasArchivo(FILE *archivo, int cantidadLineas) {
    int i = cantidadLineas-1;
    fseek(archivo, 0, SEEK_SET);
    while (i > 0){
         while(fgetc (archivo) != '\n');
         i--;
    }
}

int encontrarCantidadVertices(FILE *archivo,int cantLineas) {
    int mayor = 0;
    int aux1,aux2,aux3;
    for (int i = 0; i < cantLineas; ++i) {
        fscanf(archivo,"%d %d %d",&aux1,&aux2,&aux3);
        if (mayor == 0 || aux1 > mayor)
            mayor = aux1;
        else if (aux2 > mayor){
            mayor = aux2;
        }
    }
    return mayor;
}
