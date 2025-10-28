/*Pass a string of digits and store each digit in a circular doubly linked list using the last pointer.
 Then display only odd digits*/

 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>

 struct Node
 {
    int data;
    struct Node* next;
    struct Node* prev;
 };

 struct Node* tail;

 struct Node* createNode(int data)
 {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
 }

 void insert_end(int data)
 {
    struct Node* newNode = createNode(data);
    if(tail==NULL)
    {
        tail = newNode;
        tail->next = tail->prev = tail;
        return;
    }
    newNode->prev = tail;
    newNode->next = tail->next;
    tail->next = newNode;
    tail->next->prev = newNode;
    tail = newNode;
    
 }

 void display()
 {
    struct Node* temp = tail->next;
    do
    {
        printf("%d\t",temp->data);
        temp = temp->next;
    }while(temp!=tail->next);
 }

 void display_odd()
 {
    struct Node* temp = tail->next;
    do
    {
        if(temp->data%2!=0)
        printf("%d\t",temp->data);
        temp = temp->next;
    }while(temp!=tail->next);
 }

 int main()
 {
    printf("Enter a string of digits : ");
    char dig[50];
    scanf("%s",dig);
    for(int i=0;i<strlen(dig);i++)
    {
        insert_end(dig[i]-'0');
    }
    display();
    printf("\n");
    display_odd();
    return 0;
 }