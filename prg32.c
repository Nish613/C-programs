//stack using linked list

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("stack overflow\n");
        return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    struct Node* temp = top;
    printf("\nPopped ele : %d\n",temp->data);
    top = top->next;
    free(temp);
}

void display()
{
    struct Node* temp = top;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}
int main()
{
    printf("Enter no of items : ");
    int n,item;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&item);
        push(item);
    }
    display();
    pop();
    display();
    return 0;
}