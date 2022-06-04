#include <stdio.h>
#include "src/functions.h"


int main() {
    pueblo * village = crearPuebloVacio();
    leerArchivo("pueblo1.in", village);
    imprimirMatrizAdyacencia(village->grafo);
    FILE * archivo = fopen("pueblo1.in","r");
    int cuartel = encontrarMejorVertice(village);
    printf("mejor vertice = %d\n",cuartel);
    liberarPueblo(village);
    fclose(archivo);
    return 0;
}
