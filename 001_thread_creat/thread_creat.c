#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *thread1_entry(void *arg);
void *thread2_entry(void *arg);

int main(void)
{
    pthread_t thread_id[2] = {0, 0};
    int ret = 0;    

    if ((ret = pthread_create(&thread_id[0], NULL, thread1_entry, NULL)) != 0)
    {
        printf ("thread1 create failed!\n");
        return -1;
    }

    if ((ret = pthread_create(&thread_id[1], NULL, thread2_entry, NULL)) != 0)
    {
        printf ("thread2 create failed!\n");
        return -1;
    }

    pthread_join(thread_id[0], NULL);
    pthread_join(thread_id[1], NULL);

    printf("all threads over!\r\n");

    return 0;
}


void *thread1_entry(void *arg)
{
    int i = 5;

    while(i--)
    {
        printf("This is thread1!\n");
        sleep(1);
    }

    return NULL;
}

void *thread2_entry(void *arg)
{
    int i = 10;

    while(i--)
    {
        printf("This is thread2!\n");
        sleep(1);
    }

    return NULL;
}
