/*Selection sort*/

#include<stdio.h>

int selection(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min = j;
            }
        }
        if(min!=i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
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

    selection(arr,n);
    printf("Sorted array : \n");
    for(int i=0;i<n;i++)
    printf("%d\t",arr[i]);
    return 0;
}