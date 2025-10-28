/*Write a C program to implement a Circular Singly Linked List using First and Last   
pointers. 
Implement the following operations: 
i. Insertion at the end of the list using First and Last pointers. 
ii. Deletion from the beginning or end using First and Last pointers. 
iii. Display the list after each operation. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

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

void insert_end(int data)
{
    struct Node* newNode = createNode(data);
    if(head==NULL)
    {
        head = tail = newNode;
        newNode->next = head;
    }
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
}

void delete_front()
{
    struct Node* temp = head;
    if(head==NULL)
    return;
    head = head->next;
    tail->next = head;
    
    free(temp);

}

void delete_end()
{
    struct Node* temp = head;
    if(head==NULL)
    return;
    while(temp->next!=tail)
    {
        temp = temp->next;
    }
    tail = temp;
    temp->next = head;    
}



void display()
{
    struct Node* temp = head;
    do
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }while(temp!=head);
}

int main()
{
    printf("Enter no of ele : ");
    int n,data;
    scanf("%d",&n);
    printf("Enter ele : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        insert_end(data);
    }
    display();
    delete_front();
    display();
    delete_end();
    display();
    return 0;

}