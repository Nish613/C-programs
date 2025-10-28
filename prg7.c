#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n,i,*ptr,sum=0;
    printf("Enter no of ele : ");
    scanf("%d",&n);

    ptr=(int*)malloc(n*sizeof(int));
    if(ptr==NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    for(int i=0;i<n;i++)
    printf("%d\t",*(ptr+i));
    printf("\nEnter ele of array : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",ptr+i);
        sum+=*(ptr+i);
    }
    printf("Sum : %d",sum);
    free(ptr);
    return 0;
}