#include <stdio.h>
#include "src/functions.h"
#include <time.h>

int main(int argc, char * argv[]) {
    clock_t inicio;
    clock_t final;
    inicio = clock();
    char * nombreEntrada;
    char * nombreSalida;
    if (argv[1]!=NULL)
        nombreEntrada = argv[1];
    else
        nombreEntrada = "pueblo1.in";
    if (argv[1]!=NULL) {
        if (argv[2] != NULL)
            nombreSalida = argv[2];
    }
    else
        nombreSalida = "cuartel.out";
    printf("Archivo de entrada: %s\n",nombreEntrada);
    printf("Archivo de salida: %s\n",nombreSalida);
    pueblo * village = crearPuebloVacio();
    leerArchivo(nombreEntrada, village);
    imprimirMatrizAdyacencia(village->grafo);
    FILE * archivo = fopen("pueblo1.in","r");
    int cuartel = encontrarMejorVertice(village);
    printf("mejor vertice = %d\n",cuartel);
    escribirArchivo(nombreSalida,cuartel);
    liberarPueblo(village);
    fclose(archivo);
    final = clock();
    double segundos = (double)(final-inicio) / CLOCKS_PER_SEC;
    printf("%f segundos de ejecucion\n",segundos);
    return 0;
}
