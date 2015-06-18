#ifndef _NODE_H
#define _NODE_H

typedef struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
}Node;


//typedef Node* Node*;

Node* createNode(int n);
void deleteNode(Node* n);


#endif