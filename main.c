#include <stdio.h>
#include "src/functions.h"


int main() {
    pueblo village;
    leerArchivo("pueblo1.in", &village);
    imprimirMatrizAdyacencia(village.grafo);
    recorrerLista(village.cuarteles);
    liberarPueblo(&village);
    return 0;
}
