/*Write a function to reverse the elements of a static array in-
place using pointers.(Use case: Undoing operations or reversing
user-entered data.*/

#include<stdio.h>
void rev(int arr[],int n)
{
    int *ptr = arr;
    for(int i=0;i<n/2;i++)
    {
        int temp = *(ptr+i);
        *(ptr+i) = *(ptr+n-i-1);
        *(ptr+n-i-1) = temp;
    }
}
int main()
{
    int arr[] = {1,2,3,4};int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    rev(arr,n);

    printf("\nReversed array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}