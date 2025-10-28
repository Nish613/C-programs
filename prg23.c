/*1. Write a menu-driven C program to create a structure employee and maintain an array of structures.
 Each employee should have the following attributes

Name
Employee ID
Department
Monthly Salary 

Sort the employees by employee ID using recursive selection sort
Find the employee with the highest monthly salary */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee 
{
    char name[50];
    int id;
    char dept[50];
    float sal;
};

void rec_selection(struct employee e[],int n,int i)
{
    if(i==n-1)
    return;
    int minIndex = i;
    for(int j=i+1;j<n;j++)
    {
        if(e[j].id<e[minIndex].id)
        minIndex = j;
    }
    if(minIndex!=i)
    {
        struct employee temp = e[i];
        e[i] = e[minIndex];
        e[minIndex] = temp;
    }
    rec_selection(e,n,i+1);
}

void highsal(struct employee e[],int n)
{
    int max = 0;
    for(int i=0;i<n;i++)
    {
        if(e[i].sal>e[max].sal)
        max = i;
    }
    printf("Employee %s has max salary\n",e[max].name);
}

int main()
{
    int ch,n;
    char name[50];
    int id;
    char dept[50];
    float sal;
    
    printf("Enter no of employees : ");
    scanf("%d",&n);
    struct employee e[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter name : ");
        scanf(" %[^\n]",name);
        printf("Enter id : ");
        scanf("%d",&id);
        printf("Enter dept : ");
        scanf(" %[^\n]",dept);
        printf("Enter sal : ");
        scanf("%f",&sal);

        strcpy(e[i].name,name);
        e[i].id = id;
        strcpy(e[i].dept,dept);
        e[i].sal = sal;
    }

    while(1)
    {
        printf("Menu :\n1.Recursive selection\n2.Highest salary\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                rec_selection(e,n,0);
            }
            break;
            case 2:
            {
                highsal(e,n);
            }
            break;
            case 3:
            {
                for(int i=0;i<n;i++)
                {
                    printf("Name : %s\tID : %d\tDept : %s\tSal : %f\n",e[i].name,e[i].id,e[i].dept,e[i].sal);
                }
            }
            break;
            case 4: 
            {
                printf("Exiting\n");
                exit(0);
            }
        }
    }
    
    return 0;
}