#include "stdio.h"
#include "stdlib.h"

struct listnode
{
    int data;
    listnode *next_address;
};

/*Trace pointer initialization*/
listnode *head = NULL;
listnode *tail = NULL;

listnode *CREATE(int data)
{
    listnode *Node = (listnode *)malloc(sizeof(listnode *));
    Node->data = data;
    Node->next_address = NULL;

    return Node;
}

void insertlast(int data)
{
    /*
    CASES to handle:

    -> what if head is empty (head=tail=NULL)

    1.create temporary Linklist [Node A | X]

    2. assign head and tail both are Node A

       [Node A | X]
        head-tail

    ->if head is not empty

    [NODE A| X ]--> linklist
       tail
     1.create temporary Linklist [Node B | X]

     2.connect the temporary linklist with the address of last tail

       [NODE A|]->[Node B | X]

     3. Assign the new data as the tail

       [NODE A|]->[Node B | X]
                      Tail

    */

    if (head == NULL)
    {
        listnode *tempnode = CREATE(data);
        head = tempnode ; 
        tail = tempnode;

        //both are assign as the first node 
    }
    else
    {
        // step 1
        listnode *tempnode = CREATE(data);

        // step 2
        tail->next_address = tempnode;

        // step 3
        tail = tempnode;
    }
}