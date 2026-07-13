#include "stdio.h"
#include "stdlib.h"

struct Node
{
    int DATA;
    Node* next_address;
};

Node* head=NULL;
Node* tail=NULL;

Node* CREATE(int data)
{
    Node* Temp=(Node*)malloc(sizeof(Node*));
    Temp->DATA= data;
    Temp->next_address=NULL;

    return Temp;
}


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

       [Node B | X]->[Node A | X]
                        head
                        
     3. Assign the new data as the head

       [NODE B|]->[Node A | X]
           head           

                      */
void insert_first (int data)
{
    if (head==NULL)
    {
        Node* Temp_node = CREATE(data);
        head=Temp_node;
        tail=Temp_node;

    }
    else
    {
         Node* Temp_node = CREATE(data);
         Temp_node->next_address=head;
         head=Temp_node;
    }
}
int main()
{
    Node* Var = CREATE(5);
    Node* Var = CREATE(9);
    Node* Var = CREATE(3);
    Node* Var = CREATE(6);
    insert_first(13);
    insert_first(1);
}