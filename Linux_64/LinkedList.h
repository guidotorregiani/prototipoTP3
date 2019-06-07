/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif




LinkedList* ll_newLinkedList(void);

//sabe donde empieza y donde termina la lista
int ll_len(LinkedList* this);

Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

//
int ll_add(LinkedList* this, void* pElement);

//te muestra (devuelve la dire)
void* ll_get(LinkedList* this, int index);

//reemplaza nodo existente(modificar)
int ll_set(LinkedList* this, int index,void* pElement);

int ll_remove(LinkedList* this,int index);

//vuelve a estado original
int ll_clear(LinkedList* this);

//remueve nodos y nodo raiz
int ll_deleteLinkedList(LinkedList* this);

//me dice a partir de un puntero que indice tiene(tal vez no tenga)
int ll_indexOf(LinkedList* this, void* pElement);

//lista vacia o no
int ll_isEmpty(LinkedList* this);

//permite meter un elemento entre dos nodos existentes
int ll_push(LinkedList* this, int index, void* pElement);

//elimina pero me devuelve el contenido del nodo
void* ll_pop(LinkedList* this,int index);

//si esta o no esta en la lista(el puntero)
int ll_contains(LinkedList* this, void* pElement);

//recibe 2 listas.Si todos los elementos lista 2 estan dentro de list
int ll_containsAll(LinkedList* this,LinkedList* this2);

//"slicing" de una lista obtengo un pedazo-desde/hasta- es una nueva lista de ese pedazo.
LinkedList* ll_subList(LinkedList* this,int from,int to);

//genera copia. son dos listas distintas.
LinkedList* ll_clone(LinkedList* this);

//util al clonar y order por cosa distintas conservando criterios.
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
