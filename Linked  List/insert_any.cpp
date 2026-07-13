#include "stdio.h"
#include "stdlib.h"

struct NODE
{
    int data;
    NODE* next;
};

NODE* head= NULL;
NODE* tail=NULL;

NODE* CREATE(int data)
{
    NODE* Temp=(NODE*)malloc(sizeof(NODE));
    Temp->data=data;
    Temp->next=NULL;

    return Temp;
}

void Insert_Last(int data)
{
    if(head==NULL)
    {
        NODE* TEMP=CREATE(data);
        head=TEMP;
        tail=TEMP;
    }
    else
    {
        NODE* TEMP=CREATE(data);
        tail->next=TEMP;
        tail=TEMP;
    }
}

void Insert_first(int data)
{
    if(head==NULL)
    {
        NODE* TEMP=CREATE(data);
        head=TEMP;
        tail=TEMP;
    }
    else
    {
        NODE* TEMP=CREATE(data);
        TEMP->next=head;
        head=TEMP;
    }
}

NODE* SEARCH(int key)
{
    int count=0;
    for(NODE* i=head;i!=NULL;i=i->next)
    {
        if(count== key)
        {
            return i;

        }

        count++;

    }
}




void Insert_any(int data,int position)
{
   if(position <0)
   {
    printf("this position does not exists");
    return ;

   }
   else if (position-1 == 0)
   {
    Insert_first(data);
   }
   else
   {
    int count=0;
    NODE* i=head;

    while(i !=NULL)
    {
        if(count == position)
        {
            NODE* TEMP=CREATE(data);
            NODE* location=i->next;
            i->next=TEMP;
            TEMP->next=location;
            return;
        }
        count++;
        i=i->next;
    }
   }
   

}

void PRINT()
{
    for (NODE* i = head; i != NULL; i = i->next)
        printf("%d -> ", i->data);
    printf("NULL\n");
}

int main ()
{
   Insert_Last(9);
   Insert_Last(6);
   Insert_Last(0);
   Insert_Last(8);
   Insert_Last(3);
   Insert_Last(2);


        PRINT();
        Insert_any(10,4);

        PRINT();

}