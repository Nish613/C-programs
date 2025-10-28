//Print the elements of a linked list in reverse using recursion
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory allocation failed\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct Node* head)
{
    if(head==NULL)
    return;
    printf("%d  ",head->data);
    display(head->next);
}
void reverse(struct Node* head)
{
    if(head==NULL)
    return;
    reverse(head->next);
    printf("%d  ",head->data);
    
}

struct Node* revlist(struct Node* head)
{
    
}

int main()
{
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    display(head);
    printf("\n");
    reverse(head);
    return 0;
}