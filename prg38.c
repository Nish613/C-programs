//stack using ll

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
    if(!newNode){ 
    printf("Memory allocation failed");
    return;
    }
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

void pop()
{
    struct Node* temp = top;
    printf("Popped ele : %d\n",top->data);

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
    push(1);
    push(2);
    push(3);
    display();
    pop();
    display();
}

