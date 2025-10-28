/*Given an array of n integers and a key element, write a C program to search the element 
using linear search. */

#include<stdio.h>

int linear(int arr[],int n,int target)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==target)
        return i;
    }
    return -1;
}
int main()
{
    printf("Enter no of ele : ");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("Enter ele : \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter ele to find : ");
    int target;
    scanf("%d",&target);
    int res = linear(arr,n,target);
    if(res==-1)
    printf("Ele not found\n");
    else
    printf("Ele found at pos %d\n",res+1);
    return 0;
}
