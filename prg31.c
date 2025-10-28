//Array based stack

#include<stdio.h>
# define MAX 5

int stack[MAX],top = -1;

void push(int item)
{
    if(top==MAX-1)
    printf("Stack overflow\n");
    else
    stack[++top] = item;

}

void pop()
{
    if(top==-1)
    {
        printf("stack underflow\n");
        return;
    }
    printf("\nPopped ele : %d",stack[top--]);
}

void peek()
{
    if(top==-1)
    printf("stack underflow\n");
    else
    printf("\nTop ele : %d",stack[top]);
}

void isEmpty()
{
    if(top==-1)
    printf("stack is empty\n");
    else
    printf("Not empty\n");
}

void display()
{
    if(top==-1)
    {
        printf("Stack empty\n");
    }
    for(int i=top;i>=0;i--)
    {
        printf("%d\t",stack[i]);
    }

}

int main()
{
    printf("Enter no of items : ");
    int n,item;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&item);
        push(item);
    }
    display();
    pop();
    peek();
    isEmpty();
    return 0;
}