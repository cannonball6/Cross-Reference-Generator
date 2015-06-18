

#ifndef HashTable_hash_h
#define HashTable_hash_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "list.h"

typedef struct idxToken
{
    char* token;
    List* lineNumbers;
}idxToken;

typedef struct hashTable
{
    int size;
    idxToken** table;
}hashTable;


idxToken* createIdxToken(char* string)
{
    idxToken* temp = malloc(sizeof(idxToken));
    temp->token = (char*)malloc(sizeof(char)* 255);
    strcpy(temp->token, string);
    temp->lineNumbers = createList();
    
    return temp;
}


int hash(char* key, hashTable* ht)
{
    
    unsigned int hash_val = 0;
    while (*key != '\0')
    {
        hash_val ^= *key++;
    }
    return (hash_val % ht->size);
    
}

int almostFull(hashTable* ht);
int nextPrime(int num);
hashTable* rehash(hashTable* ht);

hashTable * createTable(int size)
{
    hashTable * ht = (hashTable*)malloc(sizeof(*ht));
    ht->size    = size;
    ht->table = malloc(sizeof(idxToken*) * size);
    
    for (int i = 0; i < ht->size ; i++)
    {
        ht->table[i] = NULL;
    }
    
    return ht;
}


int findSlot(char* key, hashTable* ht)
{
    //add string compare
    int index = hash(key, ht);
    //search until we either find the key or find the emtpy slot
    while(ht->table[index] != NULL)
    {
        if(strcmp(ht->table[index]->token, key) == 0)
        {
            break;
        }
        index = (index + 1) % ht->size;
    }
    return index;
}

int lookup(char* key, hashTable* ht)
{
    int index = findSlot(key, ht);
    
    if (ht->table[index] != NULL)
    {
        if (strcmp(ht->table[index]->token, key) == 0)       //key is in table
            return 1;
        else                        //key is not in table
            printf("Not Found");
    }
    return 0;
}
hashTable* insertLines(idxToken* token, hashTable* ht, int lineNumber)
{ //Appending line numbers to the list
    
    int index = findSlot(token->token, ht);
    
    if (ht->table[index] == NULL)
    {
        ht->table[index] = token;
        insertNode(lineNumber, ht->table[index]->lineNumbers);
    }
    
    else
    {
        insertNode(lineNumber, ht->table[index]->lineNumbers);
    }
    
    if (almostFull(ht))
    {
        ht = rehash(ht);
    }
    return ht;
}

hashTable* insert(idxToken* token, hashTable* ht)
{ //Need to append line numbers to list
    
    int index = findSlot(token->token, ht);
    
    if (ht->table[index] == NULL)
    {
        ht->table[index] = token;
        //insertNode(lineNumber, ht->table[index]->lineNumbers);
    }
    
//    else
//    {
//        insertNode(lineNumber, ht->table[index]->lineNumbers);
//    }
    
    if (almostFull(ht))
    {
        ht = rehash(ht);
    }
    return ht;
}

hashTable* rehash(hashTable* ht)
{
    hashTable* temp;
    
    int prime = nextPrime(ht->size);
    temp = createTable(prime);
    
    for (int i = 0; i < ht->size; i++)
    {
        if (ht->table[i] != NULL)
            insert(ht->table[i], temp);
    }
    
    free(ht);
    
    return temp;
}


int almostFull(hashTable* ht)
{
    float cnt = 0.0;
    for (int i=0; i < ht->size; i++)
    {
        if (ht->table[i] != NULL)
            cnt++;
    }
    float value = 0.0;
    value = (cnt/ht->size);
    //return true if table is %70 full, false if otherwise
    if (value >= .7)
        return 1;
    
    else
        return 0;
}

int nextPrime(int num)
{
    int i, j, count;
    
    for (i=num+1; 1; i++)
    {
        for(j=2,count=0; j <= i; j++)
        {
            if (i % j == 0)
            {
                count++;
            }
        }
        if (count ==1)
        {
            return i;
        }
    }
}


void printTable(hashTable* ht)
{
    for (int i = 0; i < ht->size; i++)
    {
        if (ht->table[i] != NULL)
        {
            printf("index:%d %s", i, ht->table[i]->token);
            printf("\n\tLine Numbers: ");
            printList(ht->table[i]->lineNumbers);
            printf("\n");
        }
    }
}



#endif
