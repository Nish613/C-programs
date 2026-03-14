/* Create a zombie (defunct) child process (a child with exit() call, but no 
corresponding wait() in the sleeping parent) and allow the init process to adopt it  
(after parent terminates). Run the process as background process and run “ps” 
command. */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
    pid_t pid;
    pid = fork();

    if(pid<0)
    {
        printf("fail\n");
        return -1;
    }
    else if(pid==0)
    {
        printf("Child process\n");
        printf("Child pid : %d\n",getpid());
        printf("Child Exiting\n");
        exit(0);
    }
    else
    {
        printf("Parent process\n");
        printf("Parent pid : %d\n",getpid());
        printf("Child pid : %d\n",pid);
        printf("Parent sleeping for 20 sec to make child zombie\n");
        sleep(20);
        printf("Parent exiting\n");
    }
    return 0;
}
