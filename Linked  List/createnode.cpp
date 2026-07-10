#include "stdio.h"
#include "stdlib.h"

struct listnode
{
    int data;
    listnode* next_address; /*<-- pointing the address for next data */

};

listnode* CREATE (int data)
{
    listnode* Node = (listnode*)malloc(sizeof(listnode));
    
    /*
    -> we are returning listnode as pointer because 
    we are pointig address of the next data
    -> in default malloc's data type is void so we are typecasting the malloc as the referance of temporary node datatype
    -> we are asigning the size od malloc dynamically so we are using the struct size;
    */

    Node->data = data;
    Node->next_address=NULL;

    return Node;
}

int main ()
{
    listnode* node = CREATE(5);
}