//Balenced brackets using stack

#include<stdio.h>
#include<string.h>

#define MAX 100

struct stack
{
    char stck[MAX];
    int top;
}s;

int push(char item)
{
    if(s.top==MAX-1)
    {
        printf("Stack is full\n");
        return 0;
    }
    s.stck[++s.top] = item;
    return 1;
}

char pop()
{
    if(s.top==-1)
    {
        printf("Stack empty\n");
        return '\0';
    }
    return s.stck[s.top--];
}

int checkpair(char val1,char val2)
{
    return((val1=='('&& val2==')')||(val1=='['&& val2==']')||(val1=='{'&& val2=='}'));
}

int check(char exp[],int n)
{
    for(int i=0;i<n;i++)
    {
        char ch = exp[i];
        if(ch=='('||ch=='['||ch=='{')
            push(ch);
        else if(ch==')'||ch==']'||ch=='}')
        {
            if(s.top==-1)
                return 0;
            char ch1 = pop();
            if(!checkpair(ch1,ch))
                return 0;
        }
    }
    return (s.top==-1);
}

int main()
{
    char exp[MAX];
    printf("Enter exp: ");
    scanf(" %[^\n]", exp);
    int n = strlen(exp);
    s.top = -1;

    if(check(exp,n))
        printf("Balanced\n");
    else
        printf("Unbalanced\n");

    return 0;
}

