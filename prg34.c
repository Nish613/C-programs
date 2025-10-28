/*Using pointers, traverse a static array and count how many
elements are even and how many are odd.(Use case: Processing
sensor values or survey data.)*/

#include<stdio.h>

int main()
{
    int arr[] = {12, 7, 9, 20, 33, 42, 55};  // static array (sensor/survey data)
    int n = sizeof(arr) / sizeof(arr[0]);

    int *ptr = arr;
    int even=0,odd=0;
    for(int i=0;i<n;i++)
    {
        if(*(ptr+i)%2==0)
        even++;
        else
        odd++;
    }

    printf("Total elements: %d\n", n);
    printf("Even elements: %d\n", even);
    printf("Odd elements: %d\n", odd);
    return 0;
}