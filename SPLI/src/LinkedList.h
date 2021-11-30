/*
 * LinkedList.h
 *
 *  Created on: 30 nov. 2021
 *      Author: pedro_000
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
struct Node
{
    void* pElement;                 //puntero al elemento (persona, empleado, etc.)
    struct Node* pNextNode;         //puntero al prox nodo
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;                       //cada vez que agrego o elimino un elemento size++/--
}typedef LinkedList;

#endif /* LINKEDLIST_H_ */

//Publicas
LinkedList* ll_newLinkedList(void);
Node* newNode(void);
int ll_len(LinkedList* this);                                       //devuelve el valor del campo int size
Node* getNode(LinkedList* this, int nodeIndex);
int addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement);
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index,void* pElement);
int ll_remove(LinkedList* this,int index);
int ll_clear(LinkedList* this);
int ll_deleteLinkedList(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);
int ll_isEmpty(LinkedList* this);
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);                           //elimina un elemento (los enlaces a ese elemento) y devuelve un puntero a ese elemento
int ll_contains(LinkedList* this, void* pElement);
int ll_containsAll(LinkedList* this,LinkedList* this2);
LinkedList* ll_subList(LinkedList* this,int from,int to);
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
int ll_count(LinkedList* this, int (*fn)(void* element));
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element));
LinkedList* ll_map(LinkedList* this, int(*pFunc)(void* element));

