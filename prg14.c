/*Insert an element at the rear end of the list 
(Append a new node to the end of the list)
Delete an element from the rear end of the list 
(Remove the last node in the list)*/ 

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertEnd()
{
    printf("Enter ele : ");
    int data;
    scanf("%d",&data);
    struct Node* newNode = createNode(data);
    
    if(head==NULL)
    {
        head = tail = newNode;
        return;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void deleteEnd()
{
    if(head==NULL)
    {
        printf("Empty list\n");
        return;
    }
    
    else
    {
        if(head==tail)
        {
            head=tail=NULL;
            return;
        }
        else
        {
            tail = tail->prev;
            tail->next = NULL;
        }
    }
    
}

void insert(int pos,int data)
{
    if(pos<1)
    {
        printf("Invalid\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if(pos==1)
    {
        if(head==NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return;
    }
    struct Node* temp = head;
    for(int i=1;i<pos;i++)
    {
        temp = temp->next;
    }
    if(temp==NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next!=NULL)
    temp->next->prev = newNode;
    temp->next = newNode;
}

void delete(int pos)
{
    struct Node* temp = head;
    if(head==NULL)
    {
        printf("Empty list\n");
        return;
    }

    if(pos==1)
    {
        head = head->next;
        head->prev = NULL;
    }

    for(int i=1;i<pos;i++)
    temp = temp->next;

    if(temp==NULL)
    {
        printf("Invalid position\n");
        return;
    }
    if(temp->prev!=NULL)
    temp->prev->next = temp->next;
    else if(temp->next!=NULL)
    temp->next->prev = temp->prev;
    else if(temp==head)
    head = temp->next;
    free(temp);
    
}

void display()
{
    struct Node* temp = head;
    while(temp!=NULL)
    {
        printf("%d <=> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main()
{

    insertEnd();
    insertEnd();
    insertEnd();
    insertEnd();
    insertEnd();
    display();
    deleteEnd();
    deleteEnd();
    display();
    insert(3,5);
    display();
    delete(2);
    display();
    return 0;
}