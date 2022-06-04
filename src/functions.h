#ifndef TAREA_3_FUNCTIONS_H
#define TAREA_3_FUNCTIONS_H

#endif //TAREA_3_FUNCTIONS_H

#include "TDApueblo.h"


void leerArchivo(char * nombreArchivo,pueblo * village);
void saltarLineasArchivo(FILE * archivo,int cantidadLineas);
int encontrarCantidadVertices(FILE * ,int cantLineas);
void dijkstra(TDAgrafo *grafo, int indiceVertice, int * padre, bool * visto, int * distancia);
bool quedanSinVisitar(bool * visto, int cantidadElementos);
int extraerMinimo(int * distancia, bool * visto, int cantidadElementos);

void leerArchivo(char *nombreArchivo, pueblo * village){
    FILE*pf;		   //para abrir archivo
    pf = fopen(nombreArchivo,"r");
    int cantidadAristas,cantidadVertices,i,j,k,w,cuartel,saltoDeLineas;
    if (pf ==NULL){
        printf("Error de archivo\n");
    }else{
        //Cantidad de cuarteles y aristas
        fscanf(pf, "%d %d", &village->cantidadDeCuarteles,&cantidadAristas);
        for (int l = 0; l < village->cantidadDeCuarteles; ++l) {
            fscanf(pf,"%d",&cuartel);
            insertarInicio(village->cuarteles,cuartel);
        }
        cantidadVertices = encontrarCantidadVertices(pf,cantidadAristas);
        village->grafo = crearGrafoVacio(cantidadVertices);
        village->grafo->cvertices = cantidadVertices;
        saltoDeLineas = village->cantidadDeCuarteles + 2;
        saltarLineasArchivo(pf,saltoDeLineas);
        //dependiendo de las lineas de archivo,
        // w es el peso (distancia) de la arista
        for(k=0;k<cantidadAristas;k++){
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

void dijkstra(TDAgrafo *grafo, int indiceVertice, int * padre, bool * visto, int * distancia) {
    for (int i = 0; i < grafo->cvertices; ++i) {
        padre[i] = NULL;
        visto[i] = false;
        if (grafo->adyacencias[indiceVertice][i] > 0){
            distancia[i] = grafo->adyacencias[indiceVertice][i];
            padre[i] = indiceVertice;
        }else{
            distancia[i] = -1;
        }
    }
    distancia[indiceVertice] = 0;
    visto[indiceVertice] = true;
    TDAlista * listaAdy;
    TDAlista * aux;
    while (quedanSinVisitar(visto,grafo->cvertices)){
        int minimo = extraerMinimo(distancia,visto,grafo->cvertices);
        visto[minimo] = true;
        listaAdy = obtenerAdyacentes(grafo,minimo);
        aux = listaAdy;
        while (aux != NULL){
            if (esListaVacia(aux))
                break;
            if (distancia[aux->inicio->dato] > distancia[minimo] + grafo->adyacencias[minimo][aux->inicio->dato] || distancia[aux->inicio->dato] == -1){
                distancia[aux->inicio->dato] = distancia[minimo] + grafo->adyacencias[minimo][aux->inicio->dato];
                padre[aux->inicio->dato] = minimo;
            }
            aux->inicio = aux->inicio->siguiente;
        }
    }

}

bool quedanSinVisitar(bool * visto, int cantidadElementos){
    for (int i = 0; i < cantidadElementos; ++i) {
        if (visto[i] == false)
            return true;
    }
    return false;
}

int extraerMinimo(int * distancia, bool * visto, int cantidadElementos){
    int indiceMinimo = -1;
    int minimo = 0;
    for (int i = 0; i < cantidadElementos; ++i) {
        if (!(visto[i])){
            if(minimo == 0 && distancia[i] != -1){
                minimo = distancia[i];
                indiceMinimo = i;
            }else if (distancia[i] < minimo && distancia[i] != -1) {
                minimo = distancia[i];
                indiceMinimo = i;
            }
        }
    }
    return indiceMinimo;
}
int ** caminosMinimosDesdeCuarteles(pueblo * village){
    int ** caminosMinimos = (int **) malloc(sizeof (int *) * village->cantidadDeCuarteles);
    nodo * aux = village->cuarteles->inicio;
    for (int i = 0; i < village->cantidadDeCuarteles; ++i) {
        int * padre = (int*) malloc(sizeof(int) * village->grafo->cvertices);
        bool * visto = (bool *) malloc(sizeof (bool) * village->grafo->cvertices);
        int * distancia = (int*) malloc(sizeof(int) * village->grafo->cvertices);
        dijkstra(village->grafo,aux->dato-1,padre,visto,distancia);
        caminosMinimos[i] = (int*) malloc(sizeof(int) * village->grafo->cvertices);
        for (int j = 0; j < village->grafo->cvertices; ++j) {
            caminosMinimos[i][j] = distancia[j];
        }
        free(padre);
        free(visto);
        free(distancia);
        aux = aux->siguiente;
    }
    return caminosMinimos;
}

int * cuartelMasCercano(pueblo * village){
    int ** caminosMinimos = caminosMinimosDesdeCuarteles(village);
    int * cuartelMinimo = (int*) malloc(sizeof(int) * village->grafo->cvertices);
    int distanciaMinima;
    for (int i = 0; i < village->grafo->cvertices; ++i) {
        distanciaMinima = -1;
        for (int j = 0; j < village->cantidadDeCuarteles; ++j) {
            if (distanciaMinima == -1 || caminosMinimos[j][i] < distanciaMinima)
                distanciaMinima = caminosMinimos[j][i];
        }
        cuartelMinimo[i] = distanciaMinima;
    }
    for (int i = 0; i < village->cantidadDeCuarteles; ++i) {
        free(caminosMinimos[i]);
    }
    free(caminosMinimos);
    return cuartelMinimo;
}

int sumatoriaDistancias(int * distancias,int cantidadElementos){
    int sumatoria = 0;
    for (int i = 0; i < cantidadElementos; ++i) {
        sumatoria+= distancias[i];
    }
    return sumatoria;
}

int encontrarMejorVertice(pueblo * village){
    int distanciaMinima = -1;
    int indice = -1;
    int distanciaActual;
    village->cantidadDeCuarteles+=1;
    for (int i = 0; i < village->grafo->cvertices; ++i) {
        if (buscarDato(village->cuarteles,i+1))
            continue;
        else{
            insertarInicio(village->cuarteles,i+1);
            distanciaActual = sumatoriaDistancias(cuartelMasCercano(village),village->grafo->cvertices);
            if ( distanciaActual < distanciaMinima || distanciaMinima == -1){
                distanciaMinima = distanciaActual;
                indice = i+1;
            }
        }
        eliminarInicio(village->cuarteles);
    }
    return indice;
}

void escribirArchivo(char * nombre,int interseccion){
    FILE * archivo = fopen(nombre,"w");
    fprintf(archivo,"%d",interseccion);
    fclose(archivo);
}