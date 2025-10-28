#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* newNode = NULL;

void beginsert()
{
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory not allocated\n");
        return;
    }
    if(head==NULL)
    {
        head=newNode;
        return;
    }
    int ele;
    printf("Enter element : ");
    scanf("%d",&ele);
    newNode->data = ele;
    newNode->next = head;
    head = newNode;    
}

void display()
{
    struct Node* temp = head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main()
{
    printf("Enter no of ele : ");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    beginsert();
    
    display();
    return 0;
}