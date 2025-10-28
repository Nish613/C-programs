#include <stdio.h>
int main()
{
    int a[3][3];
    printf("Enter ele : \n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Array : \n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t",a[i][j]);
            
        }
        printf("\n");
    }
}