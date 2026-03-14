/*Write a C program to load the binary executable of the previous program in a child 
process using exec system call.*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
    pid_t pid;
    pid = fork();
    
    if(pid<0)
    {
        printf("Child creation failed\n");
        return -1;
    }
    
    else if(pid==0)
    {
        printf("Child process\n");
        printf("Loading prev prg using exec\n");
        execl("./lab4p1","lab4p1",NULL);
        printf("Exec failed\n");
        exit(0);
    }
    
    else
    {
        wait(NULL);
        printf("Parent process\n");
    }
    return 0;
}
