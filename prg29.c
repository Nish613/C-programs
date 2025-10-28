/*Write a recursive C program to implement Selection Sort using pointers. 
• The recursive function should sort the array using the Selection Sort algorithm. 
• Access and manipulate the array elements using pointers (i.e., avoid using arr[i] 
style directly). 
• The program should read the array from the user in the main function, call the 
recursive sorting function, and display the sorted array. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void selection(int *arr,int n,int i)
{
    if(i==n-1)
    return;
    int minIndex = i;
    for(int j=i+1;j<n;j++)
    {
        if(*(arr+minIndex)>*(arr+j))
        minIndex = j;
    }
    if(minIndex!=i)
    {
        int temp = *(arr+minIndex);
        *(arr+minIndex) = *(arr+i);
        *(arr+i) = temp;
    }
    selection(arr,n,i+1);
}

void insertion(int *arr,int n,int i)
{
    if(i==n)
    return;
    int curr = *(arr+i);
    int prev = i-1;
    while(prev>=0&&*(arr+prev)>curr)
    {
        *(arr+prev+1) = *(arr+prev);
        prev--;
    }
    *(arr+prev+1) = curr;
    insertion(arr,n,i+1);
}
int main()
{
    printf("Enter no of ele : ");
    int n;
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    printf("Enter ele : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",arr+i);
    }
    insertion(arr,n,1);

    for(int i=0;i<n;i++)
    {
        printf("%d\t",*(arr+i));
    }
    return 0;
}