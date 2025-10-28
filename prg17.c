/*Bubble sort*/

#include<stdio.h>

void bubble(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
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

    bubble(arr,n);
    printf("Sorted array : \n");
    for(int i=0;i<n;i++)
    printf("%d\t",arr[i]);
    return 0;
}