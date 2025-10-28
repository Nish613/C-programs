 #include <stdio.h>
 void main()
 {
 int i, j, (*p)[2], a[][2]={{12, 22}, {33, 44} };
 p=a;
 for(i=0;i<2;i++)
 {
 for(j=0;j<2;j++)
 printf("%d", *(*(p+i)+j));
 }
 }