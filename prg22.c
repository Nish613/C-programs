/*doubly linked list participants -
each participant has email, name and reg. no
insert new in the middle 
delete first participant*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node
{
    char email[50];
    char name[50];
    int reg;

    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;

struct Node* createNode(char email[],char name[],int reg)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->email,email);
    strcpy(newNode->name,name);
    newNode->reg = reg;

    newNode->next = newNode->prev = NULL;
    return newNode;
}

void insert_end(char email[],char name[],int reg)
{
    struct Node* newNode = createNode(email,name,reg);
    if(head==NULL)
    {
        head = tail = newNode;
        return;
    }
    
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

}
void insert_mid(char email[],char name[],int reg)
{
    struct Node* temp = head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp = temp->next;
    }
   
    temp = head;
    for(int i=0;i<count/2;i++)
    {
        temp = temp->next;
    }

    struct Node* NewNode = createNode(email,name,reg);
    NewNode->next = temp;
    NewNode->prev = temp->prev;
    if(temp->prev!=NULL)
    temp->prev->next = NewNode;
    else
    head = NewNode;
    temp->prev = NewNode;
}

void delete_first()
{
    struct Node* temp = head;
    if(head==NULL)
    {
        printf("Empty list\n");
        return;
    }
    head = head->next;
    if(head!=NULL)
    head->prev = NULL;
    else
    tail = NULL;
    free(temp);

}

void display()
{
    struct Node* temp = head;
    while(temp!=NULL)
    {
        printf("Email : %s\tName : %s\tReg no : %d\n",temp->email,temp->name,temp->reg);
        temp = temp->next;
    }
}

int main()
{
    printf("Enter no of ele : ");
    int n;char email[50]; char name[50];int reg;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter email : ");
        scanf(" %[^\n]",email);
        printf("Enter name : ");
        scanf(" %[^\n]",name);
        printf("Enter reg no : ");
        scanf("%d",&reg);
        insert_end(email,name,reg);
    }

    display();
    insert_mid("vyhbkjl","vhbkj",33);
    printf("\n");
    display();
    delete_first();
    printf("\n");
    display();
    return 0;
}