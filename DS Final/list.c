#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "list.h"


 

List* createList()
{
	List* l;

	l = (List*)malloc(sizeof(struct list));

	l->head = NULL;
    l->tail = NULL;
    l->cnt = 0;
    
	return(l);

}

void insertNode(int data, List* l)
{
	//(int data, int index, List* l
	Node* myNode = createNode(data);

	if (isEmpty(l))
	{
		l->head = myNode;
        l->tail = myNode;
	}
	else
	{
		myNode->next = l->tail;
		
		(l->tail)->prev = myNode;
		l->tail = myNode;
	}
    l->cnt++;
}



void deleteList(List* l)
{
	Node* temp = l->head;
    
	
	while (l->head != NULL)
    {
        l->head= (l->head)->prev;
        free(temp);
        temp = l->head;
	}
    free(l);
}

int isEmpty(List* l)
{
	if (l->head == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void printList(List* l)
{
	/*if list is empty*/
	
	Node* currentPtr = l->head;

    //while not the end of the list*/
    while (currentPtr != NULL)
    {
        printf("%d ", currentPtr->data);
        currentPtr = currentPtr->prev;
    }
}
