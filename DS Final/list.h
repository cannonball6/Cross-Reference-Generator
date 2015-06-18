#ifndef _LIST_H
#define _LIST_H

#include "node.h"

typedef struct list
{
	int cnt;
	struct Node* head;
    struct Node* tail;
}List;


//typedef List* ListPtr;

List* createList();

void insertNode(int d, List* l);
void append(int data, List* l);

void removeNode(int idx,List* l);
void deleteList(List *l);

int isEmpty(List* l);
int isLast(List* l);
List* findLast(List*);

void printList(List* l);



#endif
