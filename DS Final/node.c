#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "node.h"

Node* createNode(int n)
{
	Node* temp;

	temp = (struct Node*)malloc(sizeof(Node));

	temp->data = n;
	temp->next = NULL;
	temp->prev = NULL;

	return temp;
}

void deleteNode(Node* n)
{
	free(n);

}