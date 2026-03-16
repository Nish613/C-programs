#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

int room=5;
sem_t empty,full,mutex;
int id[20];
int n;

void *thread(void * arg)
{
    int s = *(int *)arg;
    printf("Student %d req room\n",s);
    sem_wait(&empty);
    sem_wait(&mutex);
    printf("Allocated\n");
    sem_post(&mutex);
    sem_post(&full);

    sleep(10);

    sem_wait(&full);
    sem_wait(&mutex);
    printf("Leaving\n");
    sem_post(&mutex);
    sem_post(&empty);

    return NULL;

}

int main()
{
    pthread_t t1[20];
    printf("Enter number of students: ");
    scanf("%d",&n);

    printf("Enter student IDs:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&id[i]);

    sem_init(&empty,0,room);
    sem_init(&full,0,0);
    sem_init(&mutex,0,1);

    printf("Hostel booking\n");
    for(int i=0;i<n;i++)
    {
        pthread_create(&t1[i],NULL,thread,&id[i]);
    }
    for(int i=0;i<n;i++)
    {
        pthread_join(t1[i],NULL);
    }
    return 0;
}

