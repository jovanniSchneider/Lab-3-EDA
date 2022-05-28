#include <stdio.h>
#include <stdlib.h>
#include "TDAlista.h"

/*------------- estructura de datos -------------*/

typedef struct matrizGrafo 
{
	int cvertices;
	int** adyacencias;
}TDAgrafo;


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
	if (grafo->adyacencias[vertA - 1][vertB - 1] == 1) 
	{
		return 1;
	}
	return 0;
}


//NoDirigido NoPonderado
TDAgrafo* leerGrafoNoDirigido(char *nombreArchivo){
	FILE*pf;		   //para abrir archivo
	pf = fopen(nombreArchivo,"r");
	int n_vertices, m_aristas;
	int i,j,k;
	if (pf ==NULL){
		printf("Error de archivo\n");
		return NULL;
	}else{
		//Cantidad de nodos y aristas
		fscanf(pf, "%d %d", &n_vertices,&m_aristas); 		
		TDAgrafo *G=crearGrafoVacio(n_vertices);	
		//dependiendo de las lineas de archivo, 
		// 1 para grafo no dirigido no ponderado
		for(k=0;k<m_aristas;k++){
			fscanf(pf,"%d %d",&i, &j);
			G->adyacencias[i-1][j-1] = 1;
			G->adyacencias[j-1][i-1] = 1;
		}
		fclose(pf);
		return  G;	
	}
}

//Actividad 1
TDAlista* obtenerAdyacentes(TDAgrafo* grafo, int vertice);

//Actividad 2
int EsCamino( TDAgrafo* grafo, TDAlista* secuencia );

//Actividad 3
int EsCiclo( TDAgrafo* grafo, TDAlista* secuencia);










