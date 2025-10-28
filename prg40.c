//infix to postfix

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

int isOperand(char c)
{
    return ((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9'));
}

int isOperator(char c)
{
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}

int precedance(char c)
{
    if(c=='^')
    return 3;
    else if(c=='*'||c=='/')
    return 2;
    else if(c=='+'||c=='-')
    return 1;
    return 0;
}

int HighOrEqualPrecedance(char c1,char c2)
{
    int a = precedance(c1);
    int b = precedance(c2);

    if(a==b)
    {
        if(c1=='^')
        return 0;
        return 1;
    }
    return a>b;
}

void convert(char infix[],char postfix[])
{
    char stack[MAX];
    int top=-1,j=-1;

    int len = strlen(infix);

    stack[++top] = '(';
    infix[len] = ')';
    infix[len+1] = '\0';

    for(int i=0;i<strlen(infix);i++)
    {
        char ch = infix[i];

        if(ch==' ')
        continue;
        else if(ch=='(')
        stack[++top] = ch;
        else if(isOperand(ch))
        postfix[++j] = ch;
        else if(isOperator(ch))
        {
            while(top!=-1 && HighOrEqualPrecedance(stack[top],ch))
            postfix[++j] = stack[top--];
            stack[++top] = ch;
        }
        else if(ch==')')
        {
            while(top!=-1 && stack[top]!='(')
            postfix[++j] = stack[top--];
            top--;
        }
        

    }
    postfix[j] = '\0';
}
int main()
{
    char infix[MAX],postfix[MAX];
    printf("Enter infix exp : ");
    scanf(" %[^\n]",infix);

    convert(infix,postfix);
    printf("Infix : %s\n",infix);
    printf("Postfix : %s\n",postfix);
    return 0;
}