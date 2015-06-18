

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "fileio.h"


int main (void)
{
    
    hashTable* HashTable;
    HashTable = createTable(7);
    
    idxToken* Lists;
    
    Node* element;
    
    const char* delim = " (),.\"{}\t\n;<>";
    char *mode = "r+";
    char filename[] = "/Users/Cannon/Documents/Newbee.c";
    
    const char* reserved[256] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while", "_packed"};
    
    // open the file for reading
    FILE *file = fopen("/Users/Cannon/Documents/Projects/DS Final/DS Final/InputFile.c", mode);
    FILE *out = fopen("/Users/Cannon/Documents/Projects/DS Final/DS Final/Appendix.c", "w");
    
    // make sure the file opened properly
    if(NULL == file)
    {
        fprintf(stderr, "Cannot open file: %s\n", filename);
        return 1;
    }
    
    //allocate space for the file
    size_t buffer_size = 80;
    char *buffer = malloc(buffer_size * sizeof(char));
    
    // read each line and print character to the output file including generated line numbers
    int line_number = 0;
    while(-1 != getline(&buffer, &buffer_size, file))
    {
        fprintf(out, "%d: %s", ++line_number, buffer);
    
        char src[80];
        char *pch = strtok(buffer, delim);
        while (pch != NULL)
        {
            printf("%s\n", pch);
            
            strcpy(src, pch);
            HashTable = insertLines(createIdxToken(src), HashTable, line_number);
            pch = strtok(NULL, delim);
            printTable(HashTable);
            printf("\n\n");
        }
        printTable(HashTable);
        printf("\n\n");
        printf("\n\n");
    }
    
//    for (int i = 0; i < HashTable->size; i++)
//    {
//        if (HashTable->table[i] != NULL)
//        {
//            fprintf(out, "index:%d %s", i, HashTable->table[i]->token);
//            //fprintf(out, "\n\tLine Numbers: ");
//            
//            Node* currentPtr = idxToken->;
//            
//            //while not the end of the list*/
//            while (currentPtr != NULL)
//            {
//                fprintf(out,"%d ", currentPtr->data);
//                currentPtr = currentPtr->prev;
//            }
//            //printList(ht->table[i]->lineNumbers);
//            fprintf(out, "\n");
//        }
//    }
    fflush(stdout);
    
    printTable(HashTable);
    fclose(file);
    free(buffer);
    
    
    return 0;
}
