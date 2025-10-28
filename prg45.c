//Priority queue

#include<stdio.h>
#define MAX 5

int queue[MAX];
int size = 0;

void insert(int item)
{
    if(size==MAX)
    {
        printf("Full\n");
        return;
    }
    queue[size++] = item;
}

void deleteMax()
{
    if(size==0)
    {
        printf("Empty\n");
        return;
    }

    int max = 0;
    for(int i=0;i<size;i++)
    {
        if(queue[i]>queue[max])
        max=i;
    }
    printf("%d\n",queue[max]);
    for(int i=max;i<size-1;i++)
    queue[i] = queue[i+1];
    size--;

}
void display() {
    if (size == 0) {
        printf("Queue is empty!\n");
        return;
    }

    for (int i = 0; i < size; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    insert(4);
    insert(2);
    insert(5);
    insert(3);

    printf("Priority Queue: ");
    display();

    deleteMax();

    printf("After deletion: ");
    display();

    return 0;
}