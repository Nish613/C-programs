/*Given marks of 5 students in 3 subjects (use 2D array), use
pointers to:
• Calculate total marks of each student
• Find average marks of each subject
( Use case: Academic report generation)(Note: Not to use
structures)
*/

#include<stdio.h>

int main()
{
    int marks[5][3] = {
        {80, 75, 90},  // Student 1
        {60, 70, 65},  // Student 2
        {95, 85, 100}, // Student 3
        {50, 60, 55},  // Student 4
        {88, 77, 66}   // Student 5
    };
    int tot=0,tot1=0;
    int *ptr = &marks[0][0];
    for(int i=0;i<5;i++)
    {
        
        printf("Student %d \n: ",i);
        tot=0;
        for (int j=0;j<3;j++)
        {
            tot = tot+*(ptr+j);
        }
        printf("tot :  %d\n",tot);
        printf("Avg : %f\n",tot/3.0);
    }
    
    
    return 0;
}