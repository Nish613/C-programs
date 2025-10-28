//Deque using arrays

#include<stdio.h>
#define MAX 10

int deque[MAX];
int front=-1,rear=-1;

int isFull()
{
    return ((front==0&&rear==MAX-1)||front==rear+1);
}

int isEmpty()
{
    return front==-1;
}

void InsertFront(int item)
{
    if(isFull())
    {
        printf("Full\n");
        return;
    }

    if(front==-1)
    front=rear=0;

    else if(front==0)
    front=MAX-1;

    else
    front--;

    deque[front] = item;
}

void InsertRear(int item)
{
    if(isFull())
    {
        printf("Full\n");
        return;
    }

    if(front==-1)
    front=rear=0;

    else if(rear==MAX-1)
    rear=0;

    else
    rear++;

    deque[rear] = item;
}

void DeleteFront()
{
    if(isEmpty())
    {
        printf("Empty\n");
        return;
    }

    printf("%d\n",deque[front]);

    if(front==rear)
    front=rear=-1;

    else if(front==MAX-1)
    front=0;

    else
    front++;

}

void DeleteRear()
{
    if(isEmpty())
    {
        printf("Empty\n");
        return;
    }

    printf("%d\n",deque[rear]);

    if(front==rear)
    front=rear=0;

    else if(rear==0)
    rear = MAX-1;

    else
    rear--;


}

void display()
{
    int i;
    for ( i = front; i != rear; i = (i + 1) % MAX)
    printf("%d ", deque[i]);
printf("%d", deque[i]);

}

int main()
{
    InsertFront(10);   // Insert at front
    InsertRear(20);    // Insert at rear
    InsertFront(5);    // Insert another at front
    display();         // Show all elements
    DeleteFront();     // Remove from front
    DeleteRear();      // Remove from rear
    display();
    return 0;
}