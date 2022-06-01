#include <stdio.h>
#include "src/functions.h"


int main() {
    pueblo village;
    leerArchivo("pueblo1.in", &village);
    imprimirMatrizAdyacencia(village.grafo);
    recorrerLista(village.cuarteles);
    FILE * archivo = fopen("pueblo1.in","r");
    int cantidadAristas,a;
    fscanf(archivo,"%d %d",&a,&cantidadAristas);
    saltarLineasArchivo(archivo,4);
    a = encontrarCantidadVertices(archivo,cantidadAristas);
    printf("%d\n",a);
    liberarPueblo(&village);
    fclose(archivo);
    return 0;
}
