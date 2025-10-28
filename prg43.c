// circular queue using array

#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int queue[MAX];
int front=0,rear=0,count=0;

int isEmpty()
{
    return count==0;
}

void enqueue(int item)
{
    if(count==MAX)
    {
        printf("Full queue\n");
        return;
    }
    queue[rear] = item;
    rear = (rear+1)%MAX;
    count++;
}

void dequeue()
{
    if(isEmpty()){
    printf("Empty\n");
    return;}

    printf("%d\n",queue[front]);
    front = (front+1)%MAX;
    count--;
}

void display()
{
    if(isEmpty())
    {
        printf("Empty\n");
        return;
    }
    int c=count,i=front;
    while(c>0)
    {
        printf("%d\t",queue[i]);
        i=(i+1)%MAX;
        c--;
    }
    printf("\n");
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
    return 0;

}