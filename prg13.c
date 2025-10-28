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
    int ele;
    printf("Enter element : ");
    scanf("%d",&ele);
    newNode->data = ele;
    newNode->next = head;
    head = newNode;    
}

void lastinsert()
{
    struct Node* temp = head;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode==NULL)
    {
        printf("Memory not allocated\n");
        return;
    }
    
    int ele;
    printf("Enter element : ");
    scanf("%d",&ele);
    newNode->data = ele;
    newNode->next = NULL;

    if(head==NULL)
    {
        head=newNode;
        return;
    }
    while(temp->next!=NULL) 
    temp=temp->next;
    
    temp->next = newNode;
}  

void middleinsert()
{
    struct Node* temp = head;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter ele : ");
    int ele;
    scanf("%d",&ele);
    newNode->data = ele;

    printf("Enter position to insert : ");
    int pos;
    scanf("%d",&pos);

    for(int i=0;i<pos-1;i++)
    {
        if(temp==NULL)
        printf("Invalid\n");
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;


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
    beginsert();
    beginsert();
    beginsert();
    beginsert();
    display();
    lastinsert();
    lastinsert();
    lastinsert();
    display();
    middleinsert();
    display();
    return 0;
}