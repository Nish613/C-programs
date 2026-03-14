/*Write a C program to create a child process. Display different messages in parent 
process and child process. Display PID and PPID of both parent and child process. 
Block  parent process until child completes using wait system call.*/

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
        printf("Child process creation failed\n");
        return -1;
    }
    
    else if(pid==0)
    {
        printf("Child process\n");
        printf("Child pid : %d\n",getpid());
        printf("Child ppid : %d\n",getppid());
    }
    
    else
    {
        wait(NULL);
        printf("Parent process\n");
        printf("Parent pid : %d\n",getpid());
        printf("Parent ppid : %d\n",getppid());
    }

    return 0;
}

