/*Write a small function to find the smallest element in an array using pointers. 
In the main function, create a dynamically allocated array, read the values from the 
keyboard, and pass the array to the function. 
Display the result (smallest element) in the main function.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void small(int *arr,int n)
{
    int small=*arr;
    for(int i=0;i<n;i++)
    {
        if(*(arr+i)<small)
        small = *(arr+i);
    }
    printf("smallest ele : %d",small);
}

int main()
{
    printf("Enter no of ele : ");
    int n;
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter ele : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    small(arr,n);
    return 0;
}

