#include "stdio.h"
#include "stdlib.h"

struct LIST_NODE
{
    int data;
    LIST_NODE* next_address;

};

LIST_NODE* head= NULL;
LIST_NODE* tail=NULL;

LIST_NODE* CREATE(int data)
{
    LIST_NODE* Temp_Node=(LIST_NODE*)malloc(sizeof(LIST_NODE*));
    Temp_Node->data=data;
    Temp_Node->next_address=NULL;

    return Temp_Node;
}

LIST_NODE* SEARCH(int key)
{
    for(LIST_NODE* i=head;i!=NULL;i=i->next_address)
    {
        if(i->data == key)
        {
            return i;
        }

        return NULL;
    }
}


/*
1. search the position 
ex:
    [ 9 |  ]->  [ 3 |  ]->  [ 4 |  ]->  [ 6 |  ]->NULL

    suppose want to put the new data = 5 , beside data = 3;

    1.at first i will search the data location ,

            now we have two thing:  location =   [ 3 |  ] location's next address =   [ 4|  ]

    
    2. Create a temporary linklist ,insert data   [ 5 |X ]
    
    3. i.connect the temp address with location's very nest data
             
              [ 5 |  ]   -->         [ 4 |  ]
               temp             location's next data
      ii. connect location's next address to temporary data
            
               [ 3 |  ] ->  [ 5 |  ]
                location     temp


*/
void Insert_middle(int data,int position)
{
    LIST_NODE* LOCATION=SEARCH(data);
    LIST_NODE* Temp=CREATE(data);
    Temp->next_address=LOCATION->next_address;
    LOCATION->next_address=Temp;
}

