/* Write C program that utilizes pointers to increment the 
elements of an array*/

#include <stdio.h>
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

    int *ptr;
    ptr = &a[0];
    for(int i=0;i<n;i++)
    {
        *(ptr+i)=*(ptr+i)+1;
    }
    printf("\nNew Array : ");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
}