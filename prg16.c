/*Given an array of integers, implement binary search to find the position of a given key. */

#include <stdio.h>


int binary(int arr[],int n,int target)
{
    int l=0,u=n-1,mid=0;
    while(l<=u)
    {
        mid = (l+u)/2;
        if(arr[mid] == target)
        return mid;
        else if(arr[mid]<target)
        l = mid+1;
        else if(arr[mid]>target)
        u = mid-1;
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
    int res = binary(arr,n,target);
    if(res==-1)
    printf("Ele not found\n");
    else
    printf("Ele found at pos %d\n",res+1);
    return 0;
}