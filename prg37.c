//Stack implementation using arrays

#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

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
    printf("Stack underflow\n");
    else
    printf("Popped ele : %d\n",stack[top--]);
}

void peek()
{
    if(top==-1)
    printf("Stack empty\n");
    else
    printf("Top ele : %d\n",stack[top]);
}

void isEmpty()
{
    if(top==-1)
    printf("Stack empty\n");
    else
    printf("Stack not empty\n");
}

void display()
{
    if(top==-1)
    printf("Stack empty\n");
    else
    {
        for(int i=top;i>=0;i--)
        printf("%d\t",stack[i]);
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    display();
    isEmpty();
    peek();
    pop();
    display();
    isEmpty();
    peek();

}