#include "stdio.h"
#include "stdlib.h"

struct listnode
{
    int data;
    listnode* next_address;

};

listnode* CREATE (int data)
{
    listnode* Node = (listnode*)malloc(sizeof(listnode));
    Node->data = data;
    Node->next_address=NULL;

    return Node;
}

int main ()
{
    listnode* node = CREATE(5);
}