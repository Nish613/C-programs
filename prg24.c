/*2. Write a C program to manage patient details in a hospital using Doubly Linked Lists.

Each patient should have the following attributes
Name, Patient ID, Diagnosis

Write functions to 
Insert a patient in the list at a given position
Display all patients*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char name[50];
    int id;
    char diag[50];

    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;

struct Node* createNode(char name[],int id,char diag[])
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name,name);
    newNode->id = id;
    strcpy(newNode->diag,diag);

    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insert_first(char name[],int id,char diag[])
{
    struct Node* newNode = createNode(name,id,diag);
    if(head==NULL)
    {
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insert_pos(char name[],int id,char diag[],int pos)
{
    struct Node* temp = head;
    for(int i=0;i<pos;i++)
    {
        temp = temp->next;
    }
    if(temp==NULL)
    return;
    if(head==NULL)
    return;
    struct Node* newNode = createNode(name,id,diag);
    newNode->next = temp;
    newNode->prev = temp->prev;
    if(temp->prev!=NULL)
    temp->prev->next = newNode;
    else
    head = newNode;
    temp->prev = newNode;
}

void display()
{
    struct Node* temp = head;
    while(temp!=NULL)
    {
        printf("Name : %s\tID : %d\t\tDiagnosis : %s\n",temp->name,temp->id,temp->diag);
        temp = temp->next;
    }
}

int main()
{
    printf("Enter no of ele : ");
    int n;
    char name[50];
    int id;
    char diag[50];
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        printf("Enter name : ");
        scanf(" %[^\n]",name);
        printf("Enter id : ");
        scanf("%d",&id);
        printf("Enter diag : ");
        scanf(" %[^\n]",diag);

        insert_first(name,id,diag);
    }

    display();
    insert_pos("vbfreg",89,"rgwr",2);
    printf("\n");
    display();
    return 0;
}