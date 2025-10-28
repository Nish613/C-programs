#include <stdio.h>
 int main() {
 int arr[4] = {12, 20, 39, 43};
 int *ptr;
 ptr = &arr[0];
 // ptr points to the beginning of the array
 printf("%d\n", arr[0]);
 // prints 12
 printf("%d\n", *ptr);
 // prints 12
 printf("%d\n", *ptr + 1); // prints 13
 printf("%d\n", (*ptr) + 1); // prints 13
 printf("%d\n", *(ptr + 1)); // prints 20
 ptr += 2;
 // ptr nowpoints to arr[2]
 printf("%d\n", *ptr);
 // prints 39
 *ptr = 38;
 // arr[2] is now 38
 printf("%d\n", *ptr- 1); // prints 37
 ptr++;
 // ptr nowpoints to arr[3]
 printf("%d\n", *ptr);
 // prints 43
 (*ptr)++;
 // arr[3] becomes 44
 printf("%d\n", *ptr);
 // prints 44
 return 0;
 }