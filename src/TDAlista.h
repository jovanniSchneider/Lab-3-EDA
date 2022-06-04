#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*------------- estructura de datos -------------*/

typedef struct nodoGenerico
{
  int dato;
  struct nodoGenerico* siguiente;
}nodo;

typedef struct listaGenerica
{
  nodo* inicio;
}TDAlista;


/*------------- operaciones -------------*/

TDAlista* crearListaVacia()
{
  TDAlista* lista=(TDAlista*)malloc(sizeof(TDAlista));
  lista->inicio=NULL;
  return lista;
}

bool esListaVacia(TDAlista* lista)
{
  if (lista->inicio == NULL)
    return true;
  else
    return false;
}

void recorrerLista(TDAlista* lista)
{
  if (!esListaVacia(lista))
  {
    nodo* auxiliar=lista->inicio;
    while (auxiliar!=NULL)
    {
      printf("%d ",auxiliar->dato);
      auxiliar=auxiliar->siguiente;
    }
    printf("\n");
  }
  else
    printf("La lista está vacía\n");
}

void insertarInicio(TDAlista* lista, int dato)
{
  nodo* nuevo=(nodo*)malloc(sizeof(nodo));
  nuevo->dato=dato;
  nuevo->siguiente = lista->inicio;
  lista->inicio=nuevo;
}

void eliminarInicio(TDAlista* lista)
{
  nodo* auxiliar;
  if(!esListaVacia(lista))
  {
    auxiliar=lista->inicio;
    lista->inicio=lista->inicio->siguiente;
    free(auxiliar);
  }
}


/*------------- Actividad 2 -------------*/
//Funcion: Elimina toda una lista enlazada
//No es necesario usar free ya que se usa en eliminarInicio;
void liberarLista(TDAlista * lista){
    while (!esListaVacia(lista))
    {
        eliminarInicio(lista);
    }
}


bool buscarDato(TDAlista* lista, int dato){
    nodo* auxiliar=lista->inicio;
    while (auxiliar!=NULL)
    {
        if (dato == auxiliar->dato){
            return true;
        }
        auxiliar = auxiliar->siguiente;
    }
    return false;
}

int obtenerNumeroNodos(TDAlista* lista);

/*------------- Actividad 3 -------------*/
void insertarNodoFinal(TDAlista* lista, int dato);
void insertarNodoDespues(TDAlista* lista, int dato, int datoAnterior);
void eliminarFinal(TDAlista* lista);
void eliminarDato(TDAlista* lista, int dato);
nodo* obtenerNodo(TDAlista* lista, int posicion);
