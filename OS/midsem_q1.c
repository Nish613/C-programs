#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int n;
int tq=4;
struct Process
{
    int pid,at,bt,priority,ct,tat,wt,rt;

};
struct Process p[10];
void * thread1(void * arg)
{
    struct Process temp;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].at>p[j+1].at||p[j].at==p[j+1].at&&p[j].priority<p[j+1].priority)
            {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        printf("%d ",p[i].pid);
    }
    printf("\n");
}

void * thread2(void * arg)
{
    int time=0,done;
    printf("Gantt chart\n");
    do
    {
        for(int i=0;i<n;i++){ 
        done=1;
        if(p[i].rt>0)
        {
            done=0;
            printf("|p%d|",p[i].pid);
            if(p[i].rt>tq)
            {
                time+=tq;
                p[i].rt-=tq;
                
            }
            else
            {
                time+=p[i].rt;
                p[i].rt=0;
                p[i].ct=time;
            }
        }
    }
    }
    while(done==0);
}

int main()
{
    pthread_t t1,t2;
    printf("Enter no of process : ");
    
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        p[i].pid = i+1;
       
        printf("Process %d\n",i+1);
        printf("AT : ");
        scanf("%d",&p[i].at);
        printf("BT : ");
        scanf("%d",&p[i].bt);
        printf("Priority : ");
        scanf("%d",&p[i].priority);
         p[i].rt = p[i].bt;
    }



    pthread_create(&t1,NULL,thread1,NULL);
    pthread_join(t1,NULL);

    pthread_create(&t2,NULL,thread2,NULL);
    pthread_join(t2,NULL);

    printf("\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        p[i].tat = p[i].ct-p[i].at;
        p[i].wt = p[i].tat-p[i].bt;
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d",p[i].pid,p[i].at,p[i].bt,p[i].priority,p[i].ct,p[i].tat,p[i].wt);
        printf("\n");
    }
    double atat=0,awt=0;
    for(int i=0;i<n;i++)
    {
        atat += p[i].tat;
        awt += p[i].wt;
    }
    printf("\nATAT : %f",atat/n);
    printf("\nAWT : %f",awt/n);
    return 0;
}
