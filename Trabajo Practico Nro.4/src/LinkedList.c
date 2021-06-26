#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{	//creo la lista, donde va a ir el nodo
    LinkedList* this= NULL;

    //Crea espacio en memoria dinamica para un lista
    this =(LinkedList*) malloc(sizeof(LinkedList));

    if(this!=NULL){ //valido
    	this -> size = 0; //inicializando al tamaño
    	this -> pFirstNode = NULL; //el proximo nodo apunta a null
    }

    //Si está todo bien, devuelve la dirección de memoria.

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    //Corrobora que el if no sea null
    if(this!=NULL){
    	//Si no es null, retorna el size de la lista
    	returnAux = this -> size;
    }
    //Devuelve el tamaño de la lista. Que devuelve el size
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int i;
    int cantidadLista;

    // Se asigna el tamaño de la lista
    cantidadLista=ll_len(this);

    //Se valida el this y que la lista sea mayor a 0
    if(this!=NULL&&cantidadLista>0 && nodeIndex>=0&&nodeIndex<cantidadLista)
    {	//Se valida el index ingresado por el usuario y que este dentro del rango máximo  y minimo de la lista
            //Si es el primero, en la posición 0, se le asigna el primer nodo
            if(nodeIndex==0)
            {	//Si es el primer nodo, se apunta a la lista
                pNode=this->pFirstNode;
            }
            else
            {	//Se guarda el node en la posición 0
                pNode=this->pFirstNode;
                for(i=0; i<nodeIndex; i++) //recorre el for , nodo por nodo hasta encontrar el que quiero
                {	//Cuando llega se hace que pNode apunte al nodo según el index que ingreso el usuario
                    pNode = pNode->pNextNode;
                }
            }
    }

    return pNode; //retorna
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux;
    int cantidadLista;

    //creo nodos
    Node* pNode=NULL;
    Node* pNodeAnterior=NULL;
    Node* pNodeSiguiente=NULL;

    cantidadLista=ll_len(this); //obtengo el tamaño de la lista

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=cantidadLista) //valido
    {
        pNode=(Node*)malloc(sizeof(Node));
     //   pNodeAnterior=(Node*)malloc(sizeof(Node)); //Se crea espacio en la memoria //ojo

        pNodeSiguiente=getNode(this, nodeIndex); //le doy un espacio de memoria
        pNode->pElement=pElement; //apunto el * elemento a la posicion 0
        if(nodeIndex==0) //si es el primer nodo
        {
            pNode->pNextNode=this->pFirstNode; //el pNextNode del nuevo nodo apunta al pFirstNode de la lista
            this->pFirstNode=pNode; //pFirstNode de la lista apunta al primer nodo
        }
        else//si no es el primer
        {
            pNodeAnterior=getNode(this, nodeIndex-1);//obtengo el ubicado en la posicion anterior al nuevo nodo que voy a agregar
            pNodeAnterior->pNextNode=pNode;//apunto el nodo anterior a mi nuevo nodo
            pNode->pNextNode=pNodeSiguiente;//apunto mi nuevo nodo al nodo anterior
        }
        this->size++;//agrego un lugar a la lista
        returnAux=0;//retorno 0
    }
    else
    {
        returnAux=-1; //ojo
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux;
    int ultimoIndex;

    //Se obtiene el tamaño de la lista,
    //para saber cual es el ultimo lugar
    ultimoIndex=ll_len(this);

    //Se valida
    if(this!=NULL)
    {	//Agrego al Nodo y devuelvo 0 si funciona
        addNode(this, ultimoIndex, pElement);
        returnAux=0;
    }
    else{
        returnAux=-1; //ojo
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    int cantidadLista;
    void* returnAux=NULL;
    //creo el nodo
    Node* pNode=NULL;

    //Obtengo el tamaño de la lista
    cantidadLista=ll_len(this);

    //Valida
    if(this!=NULL && index>=0&&index<cantidadLista)
    {	//Crea espacio en la memoria para crear un nodo
            pNode=getNode(this,index); //Obtengo un nodo en la lista, segun el index
            returnAux=pNode->pElement;//retorno el puntero al elemento encontrado
        }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux;
    int cantidadLista;
    Node* pNode=NULL;

    //Obtengo el tamaño de la lista
    cantidadLista=ll_len(this);

    //Valido
    if(this!=NULL && index>=0&&index<cantidadLista) //
    {
       	//Obtengo un nodo de la lista segun el index
            pNode=getNode(this,index);
            pNode->pElement=pElement; //guardo pElement al nodo solicitado - optimizar
            returnAux = 0;
    } else{
           returnAux=-1; //ojo
        }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux;
    int cantidadLista;

    // creo nodos

    Node* pNode;
    Node* pNodeAnterior=NULL;
    Node* pNodeSiguiente=NULL;


    cantidadLista=ll_len(this); // Se obtiene el tamaño de la lista

    if(this!=NULL && index>=0&&index<cantidadLista) //valido - ojo
    {
     /*   pNode=(Node*)malloc(sizeof(Node));
        pNodeAnterior=(Node*)malloc(sizeof(Node)); //crea espacio en la memoria x3 //ojo
        pNodeSiguiente=(Node*)malloc(sizeof(Node));*/
            pNode=getNode(this,index); //obtengo nodo a borrar segun el index

            if(index==0) //si es el primer nodo
            {
                this->pFirstNode=pNode->pNextNode; //guardo la direccion del primer nodo
            }
            else //si no es el primer nodo
            {
                pNodeAnterior=getNode(this,index-1); //al anterior nodo comprueba si es
                pNodeSiguiente=getNode(this,index+1); //comprueba el siguiente nodo para ver si es //ojo
                pNodeAnterior->pNextNode=pNodeSiguiente; //se le asgina la dirección de memoria al siguiente nodo borrado
            }								//actual - ojo
            free(pNode);//borro el nodo solicitado
            this->size--; //achico un lugar la lista
            returnAux=0;
    }else{
            returnAux=-1; //ojo
        }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux;
    int cantidadLista;
    int i=0;


    cantidadLista=ll_len(this); //obtengo el tamaño de la lista

    if(this!=NULL&&cantidadLista>0)
    {
        for(i=cantidadLista-1; i>=0; i--) //recorro lista
        {
            ll_remove(this,i); //recorro la lista y borro uno por uno
            returnAux = 0;
        }
    }else{
        returnAux=-1; //ojo
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux;

    if(this!=NULL) //valido
    {
        ll_clear(this); //herramienta para borrar
        free(this); //borro la lista
        returnAux = 0;
    }else
    {
        returnAux=-1; //
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux;
    int cantidadLista;
    int i;

    Node* pNode;

    cantidadLista=ll_len(this); //Obtengo el tamaño de la lista

    if(this!=NULL) //valido
    {
        for(i=0; i<cantidadLista; i++) //corro la lista
        {
            pNode=getNode(this,i); //recorro la lista obteniendo nodo por nodo
            if(pNode->pElement==pElement) //si pElemento es igual al pElement de alguno de los nodos recorridos...
            {
                returnAux=i; //devuelve la posicion del nodo con la primer ocurrencia
                break; //una vez encontrada rompe la condicion
            }
            else
            {
                returnAux=-1;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux;
    int cantidadLista;

    if(this!=NULL) //valido
    {
        cantidadLista=ll_len(this); //Obtengo el tamaño de la lista
        if(cantidadLista==0) //valido
        {
            returnAux=1; //si el tamaño de la lista es igual a 0 retorno 1
        }else if(cantidadLista>0){  //si el tamaño de la lista es mayor a 0 retorno 0 - ojo
            returnAux=0;
        }
    }
    else{
        returnAux=-1; //ojo
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux;
    int cantidadLista;

    cantidadLista=ll_len(this); //Obtengo el tamaño de la lista
    if(this!=NULL && index>=0&&index<=cantidadLista) //valido
    {
            addNode(this, index, pElement); //agrego el nodo en la posición indicada
            returnAux = 0;
    }else{
        returnAux=-1; //ojo
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int cantidadLista;

    cantidadLista=ll_len(this); //obtengo el tamaño de la lista
    if(this!=NULL && index>=0&&index<cantidadLista) //valido
    {
            returnAux = ll_get(this, index); //apunto pElement al puntero que se va a eliminar
            ll_remove(this, index); //borro el elemento segun el indice
    }
    //retorno
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux;
    int i;
    int cantidadLista;

    Node* pNode;

    cantidadLista=ll_len(this);

    returnAux=0;

    if(this!=NULL)
    {
        for(i=0; i<cantidadLista; i++) //recorro la lista
        {
            pNode=getNode(this, i); //busco el elemento en la lista
            if(pNode->pElement==pElement) //ojo
            { //si el elemento está retorna 1
                returnAux=1;
                break;
            }else{
            	returnAux=-1;
            }
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux;
    int cantidadLista;
    int i;

    LinkedList* listaUno=this; //obtengo el tamaño de la 1era lista
    LinkedList* listaDos=this2; //obtengo el tamaño de la 2da lista
    Node* pNodeListaDos;

    cantidadLista=ll_len(this);

    if(listaUno!=NULL&&listaDos!=NULL)
    {
        for(i=0; i<cantidadLista; i++) //recorro la lista
        {
            pNodeListaDos=getNode(listaDos,i); //determino que los elementos estén en la lista

            if(ll_contains(listaUno,pNodeListaDos->pElement)!=1)
            {
                returnAux=0;
                break;
            }
            else
            {
                returnAux=1; //
            }
        }
    }else{
        returnAux=-1; //ojo
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    int cantidadLista;
    int i;
    LinkedList* cloneArray=NULL;
    Node* pNode=NULL;

   	cantidadLista=ll_len(this); //Obtengo el tamaño de la lista
    if(this!=NULL && from>=0&&from<cantidadLista&&to>=0&&to<=cantidadLista&&to>from) //Valido
    {
            cloneArray=ll_newLinkedList(); //Obtengo un espacio en la memoria para la lista clonada
            for(i=from; i<to; i++) //recorro desde y hasta el numero indicado
            {
                pNode=ll_get(this,i); //copio uno por uno los nodos
                ll_add(cloneArray,pNode); //agrego cada nodo a la lista
            }
    }
    //retorna el puntero del nodo clonado si pasa ok
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    int cantidadLista;
    int i;
    LinkedList* cloneArray=NULL;
    Node* pNode=NULL;

    cantidadLista=ll_len(this); //Se obtiene un tamaño de la lista

    if(this!=NULL) //Valido
    {
        cloneArray=ll_newLinkedList(); //obtengo un espacio en memoria para la lista clonada

        for(i=0; i<cantidadLista; i++) //recorro la lista - optimizar
        {
            pNode=ll_get(this,i); //copio la lista en el nuevo linkedList y retorno
            ll_add(cloneArray,pNode);
        }
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList *this, int (*pFunc)(void*, void*), int order) {
	int returnAux = -1;
	//Crear nodos
	void *pFirstNode = NULL;
	void *pSecondNode = NULL;

	int length = ll_len(this); //Obtengo  el tamaño de la lista
	int flagSwap = 0; //Inicializo en 0 la bandera

	if (this != NULL && pFunc != NULL && (order == 1 || order == 0)) { //valido
		do {
			flagSwap = 1; //La bandera toma valor 1

			for (int i = 0 ; i < length - 1 ; i++) { //recorro el listado
				pFirstNode = ll_get(this, i); //tomo el puntero elemento de cada nodo
				pSecondNode = ll_get(this, i + 1); //tomo el puntero elemento del siguiente nodo

				if ((pFirstNode != NULL && pSecondNode != NULL)) { //valido que existan, que no sean null - ojo, optimizar

					if ((order == 1 && pFunc(pFirstNode, pSecondNode) > 0) //ordena de mayor a menor, segun el valor de orden
						|| (order == 0 && pFunc(pFirstNode, pSecondNode) < 0)) { //ojo
						flagSwap = 0; //si existe, rompe el bucle
						ll_set(this, i, pSecondNode); //al nodo en la lista i, le doy el valor de * elemento
						ll_set(this, i + 1, pFirstNode); //le agrego al siguiente nodo
					}
				}
			}
		} while (flagSwap == 0); //rompe la condicion si es igual a 0
		returnAux = 0;
	}
return returnAux; //retorna el resultado
}

