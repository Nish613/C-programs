//balenced paranthesis stack

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

char stack[MAX];
int top=-1;

void push(char item)
{
    if(top==MAX-1)
    printf("Stack overflow\n");
    else
    {
        stack[++top]=item;

    }

}

void pop()
{
    if(top==-1)
    printf("Stack underflow\n");
    else
    top--;
}

void check(char item)
{
    if(item=='('||item=='['||item=='{')
    push(item);
    else if((item==')'&&stack[top]=='(')||(item==']'&&stack[top]=='[')||(item=='}'&&stack[top]=='{'))
    pop();
    else if(item == ')' || item == ']' || item == '}')
    top=0;
}

int main()
{
    printf("Enter exp : ");
    char exp[MAX];

    scanf("%s",exp);

    for(int i=0;i<strlen(exp);i++)
    {
        check(exp[i]);

    }
    if(top==-1)
    printf("Balenced");
    else
    printf("Unbalenced");
}