#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<string.h>
#include<stdio.h>
#define N 5
pthread_mutex_t chops2[N];
int chops[N];
using namespace std;

bool isCanBoth(int i) {// for avoiding dead lock
    //the phils can get chops only when he can get both chops
    if (chops[i] && chops[(i+1)%N]) {
        chops[i]=0;
        chops[(i+1)%N]=0;
        return true;
    } else {
        return false;
    }
}

void * philosopher(void* arg) {
    int i = *((int *)arg);// the index, pay attention to the way to trans args
    while (true) {
        if (isCanBoth(i)) {
            printf("[Philosopher---%d] is eatting.\n", i);
            chops[i]=1;
            chops[(i+1)%N]=1;
            sleep(2);
        } else {
            printf("[Philosopher---%d] is thinking.\n", i);
            sleep(1);
        }

    }
    
}
void * philosopher2(void* arg) {
    int i = *((int *)arg);// the index, pay attention to the way to trans args
    while (true) {
        if (pthread_mutex_trylock(&chops2[i]) == 0) {
            if (pthread_mutex_trylock(&chops2[(i+1)%N]) == 0) {
                printf("[Philosopher---%d] is eatting.\n", i);
                sleep(1);
                pthread_mutex_unlock(&chops2[i]);
                sleep(1);
                pthread_mutex_unlock(&chops2[(i+1)%N]);
                sleep(1);
            } else {
                printf("[Philosopher---%d] is thinking.\n", i);
                sleep(2);
                pthread_mutex_unlock(&chops2[i]);
            }
        } else {
            printf("[Philosopher---%d] is thinking.\n", i);
            sleep(1);
        }

    }
}

int main()
{
    //memset(chops,1,N);
    for (int i=0; i< N; i++) chops[i]=1;
    pthread_t philo[N];
    int err;
    for (int i = 0; i< N; i++) {
        err = pthread_create(&philo[i], NULL, philosopher2, (void *)&i);
        if (err != 0) {
            printf("pthread %d create error", i);
        }
    }
    while (true) pause;
    return 0;
}
