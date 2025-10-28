//Multiple queues (array of queues using LL)

#include<stdio.h>
#include<stdlib.h>

#define MAXQ 3

struct Node
{
    int item;
    struct Node* next;
};

struct Node* front[MAXQ];
struct Node* rear[MAXQ];

void initqueue()
{
    for(int i=0;i<MAXQ;i++)
    {
        front[i] = NULL;
        rear[i] = NULL;
    }
}

int isEmpty(struct Node* temp)
{
    return temp==NULL;
}

void enqueue(int q,int item)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    if(temp==NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    temp->item=item;
    temp->next=NULL;

    if(front[q]==NULL)
    front[q] = temp;
    else
    rear[q]->next = temp;
    rear[q] = temp;
}

void dequeue(int q)
{
    if(front[q]==NULL)
    {
        printf("Empty\n");
        return;
    }
    struct Node* temp = front[q];
    int item = temp->item;
    front[q] = temp->next;
    free(temp);

    if(front[q]==NULL)
    rear[q] = NULL;
    printf("%d\n",item);
}

void peek(int q)
{
    printf("%d\n",front[q]->item);
}

void display()
{
    for(int q=0;q<MAXQ;q++)
    {
        if(front[q]==NULL)
        return;
        struct Node* temp = front[q];
        while(temp!=NULL)
        {
            printf("%d\t",temp->item);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main()
{
    initqueue();
    
    enqueue(0,10);
    enqueue(0,20);
    enqueue(0,30);
    enqueue(1,100);
    enqueue(1,200);
    display();
    dequeue(0);
    display();
    peek(1);


    return 0;
}

