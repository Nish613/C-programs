#include <stdio.h>
int binary(int a[],int l,int u,int target)
{
    int mid = l+(u-l)/2;
    if(a[mid]>target)
    return binary(a,l,mid-1,target);
    else if(a[mid]<target)
    return binary(a,mid+1,u,target);
    else
    return mid;
    return -1;
}
int main()
{
    printf("Enter no of ele : ");
    int n;
    scanf("%d",&n);
    int a[n];
    printf("Enter ele : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Array : ");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);

    printf("Enter ele to search : ");
    int target;
    scanf("%d",&target);

    int res = binary(a,0,n,target);
    if(res==-1)
    printf("Ele not found\n");
    else 
    printf("Ele found at %d index\n",res+1);

}