/*Create a SLL which stores a single word(String)  in the list .

Perform following operations(as functions ) : 
 
1. Inset a word at the middle of the list 
2. Display all those words which has "and" as it's substring , also keep count of such words in the list*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char data[50];
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(char data[])
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void insert_end(char data[])
{
    struct Node* temp = head;
    struct Node* newNode = createNode(data);
    if(head==NULL)
    {
        head = newNode;
        return;
    }
    
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;

}

void insert_mid(char data[])
{
    struct Node* newNode = createNode(data);
    int count=0;
    struct Node* temp = head;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
    temp = head;
    for(int i=0;i<count/2-1;i++)
    {
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
        printf("%s\t",temp->data);
        temp = temp->next;
    }
}

void count()
{
    struct Node* temp = head;
    while(temp!=NULL)
    {
        if(strstr(temp->data,"and"))
        printf("%s\t",temp->data);
        temp = temp->next;
    }
}
int main()
{
    printf("Enter no of ele : ");
    int n;char data[50];
    scanf("%d",&n);
    printf("Enter word : ");
    for(int i=0;i<n;i++)
    {
        
        scanf("%s",data);
        insert_end(data);
    }
    display();
    count();
    return 0;
}