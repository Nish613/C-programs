/*Parent process : takes no. of students as input from user and takes 
their ID and request time as input. Display the details. 
Child process : create a seperate program for child process to 
simulate hostel booking using semaphores . 
The total no.of available rooms are 5 . 
If no.of students trying to book hostel exceeds 5 , they cannot 
book a room. Parent process : load the child program as executable in 
the parent process.*/

#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
    printf("Enter no of students : ");
    int n;
    int id[20],rt[20];
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("ID : ");
        scanf("%d",&id[i]);
        printf("Request time : ");
        scanf("%d",&rt[i]);
    }

    printf("\nID\tRT\n");
    for(int i=0;i<n;i++)
    {
        
        printf("%d\t%d\n",id[i],rt[i]);
    }

    pid_t pid=fork();

    if(pid==0)
    {
        execl("./child","child",NULL);
    }
    else
    {
        wait(NULL);
        printf("Child finished\n");
    }
    return 0;
}



