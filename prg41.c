//Queue using arrays

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int queue[MAX];
int front=-1,rear=-1;

int isEmpty()
{
    return front==-1;
}

int isFull()
{
    return rear==MAX-1;
}

void enqueue(int item)
{
    if(isFull())
    {
        printf("Queue is full\n");
        return;
    }
    if(front==-1)
    front=0;
    queue[++rear] = item;
}

void dequeue()
{
    if(isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Dequeued ele : %d\n",queue[front]);
    if(front==rear)
    front=rear=-1;
    else
    front++;
    
}

void peek()
{
    if (isEmpty()) {
        printf("Queue is empty!\n");
        return;}
    printf("Front ele : %d\n",queue[front]);
    return;
}

void display()
{
    if(isEmpty())
    {
        printf("Queue empty\n");
        return;

    }
    for(int i=front;i<=rear;i++)
    printf("%d\t",queue[i]);
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    dequeue();
    display();
    peek();
    printf("%d \n",isEmpty());
    printf("%d \n",isFull());
    return 0;
}
