#include <stdio.h>
#include <stdlib.h>

/*------------- estructura de datos -------------*/

typedef struct nodoGenerico
{
  int * dato;
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


//Verifica si la lista está vacia
int esListaVacia(TDAlista* lista)
{
  if (lista->inicio == NULL)
    return 1;
  else
    return 0;
}

//Entrada: Una lista de horarios y una funcion que debe recibir un nodo y un string
//Salida: No entrega
//Funcion: Recorre la lista enlazada y aplica la funcion pasada por parametro a cada nodo
void recorrerLista(TDAlista* lista, void (*f)(nodo*,char*),char * string)
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

//Funcion: inserta un nodo al inicio de la lista
void insertarInicio(TDAlista* lista, int * dato)
{
  nodo* nuevo=(nodo*)malloc(sizeof(nodo));
  nuevo->dato=(int *)malloc(sizeof(int)*2);
  nuevo->dato[0] = dato[0];
  nuevo->dato[1] = dato[1];
  nuevo->siguiente = lista->inicio;
  lista->inicio=nuevo;
}

//Funcion: Elimina el primer elemento de la lista enlazada
void eliminarInicio(TDAlista* lista)
{
  nodo* auxiliar;
  if(!esListaVacia(lista))
  {
    auxiliar=lista->inicio;
    lista->inicio=lista->inicio->siguiente;
    free(auxiliar->dato);
    free(auxiliar);
  }
}

//Funcion: Elimina toda una lista enlazada
//No es necesario usar free ya que se usa en eliminarInicio;
void liberarLista(TDAlista * lista){
	while (!esListaVacia(lista))
	{
		eliminarInicio(lista);
	}
}



int buscarDato(TDAlista* lista, int dato);
int obtenerNumeroNodos(TDAlista* lista);

/*------------- Actividad 3 -------------*/
void insertarNodoFinal(TDAlista* lista, int dato);
void insertarNodoDespues(TDAlista* lista, int dato, int datoAnterior);
void eliminarFinal(TDAlista* lista);
void eliminarDato(TDAlista* lista, int dato);
nodo* obtenerNodo(TDAlista* lista, int posicion);
