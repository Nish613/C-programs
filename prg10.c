#include<stdio.h>
#include<stdlib.h>
int small(int n,int *arr)
{
    int s = *arr;
    for(int i=1;i<n;i++)
    {
        if(*(arr+i)<s)
        s=*(arr+i);
    }
    return s;
}

int main()
{
    printf("Enter no of ele : ");
    int n;
    scanf("%d",&n);
    int *arr = (int *)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    printf("Enter ele : \n");
    for(int i=0;i<n;i++)
    scanf("%d",arr+i);

    int smallest = small(n,arr);
    printf("Smallest  : %d",smallest);
    free(arr);
    return 0;
}
