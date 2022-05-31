#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"
/*------------- estructura de datos -------------*/

typedef struct matrizGrafo 
{
	int cvertices;
	int** adyacencias;
}TDAgrafo;

//Definicion de funciones

TDAgrafo * crearGrafoVacio(int vertices);
void imprimirMatrizAdyacencia(TDAgrafo* grafo);
int adyacenciaNodos(TDAgrafo * grafo, int vertA, int vertB);
void liberarGrafo(TDAgrafo * grafo);
TDAlista * encontrarVerticesNoConexos(TDAgrafo grafo);


/*----------------- operaciones -----------------*/

TDAgrafo* crearGrafoVacio(int vertices) 
{
	TDAgrafo* grafo = (TDAgrafo*)malloc(sizeof(TDAgrafo));
	grafo->cvertices = vertices;
	grafo->adyacencias = (int**)malloc(vertices * sizeof(int*));
	int i,j;
	for (i = 0; i < vertices; i++) 
	{
		grafo->adyacencias[i] = (int*)malloc(vertices * sizeof(int));
		//Inicializa en cero
		for(j=0;j<vertices;j++){
			grafo->adyacencias[i][j] = 0;
		}	
	}
	return grafo;
}

void imprimirMatrizAdyacencia(TDAgrafo* grafo) 
{
	int i, j;
	
	for (i = 0; i < grafo->cvertices; i++) 
	{
		for (j = 0; j < grafo->cvertices; j++) 
		{
			printf("%d ", grafo->adyacencias[i][j]);
		}
		printf("\n");
	}
}

int adyacenciaNodos(TDAgrafo * grafo, int vertA, int vertB) 
{
	if (grafo->adyacencias[vertA - 1][vertB - 1] != 0)
	{
		return 1;
	}
	return 0;
}

void liberarGrafo(TDAgrafo * grafo){
    for (int i = 0; i < grafo->cvertices; ++i) {
        free(grafo->adyacencias[i]);
    }
    free(grafo->adyacencias);
    free(grafo);
}











