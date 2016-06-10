#include<iostream>
#include<unistd.h>
#include<pthread.h>
#include<sstream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#define N 10
using namespace std;

int i = 0, j = 0;

void * producer(void* arg) {
    while (i < N) {
        i+=2;
        pthread_t threadID = pthread_self();
        printf("%s %ld %s %d %s %d\n","producer ",threadID," produce 2 productions : ",i-2,"and",i-1);
        sleep(3);
    } 
    pthread_exit((void*)0);
}

void * consumer(void* arg) {
    while (j < N) {
        if (j <= i) {
            j++;
            pthread_t threadID = pthread_self();
            printf("%s %ld %s %d\n","consumer ",threadID," comsumer 1 production : ",j-1);
            sleep(1);
         } else {
            pthread_t threadID = pthread_self();
            printf("%s %ld %s\n","consumer ",threadID," is waitting ...... ");
            sleep(1);
        }
    }
    pthread_exit((void*)0);
}

void error(int err) {
    if (err != 0)
    {
        cout<<"error occurs"<<endl;
    }
}

int main()
{
    int err;
    void** tret;
    pthread_t p_tid1, p_tid2;
    pthread_t c_tid1, c_tid2, c_tid3, c_tid4, c_tid5;
    //for schedule, not using array
    err = pthread_create(&p_tid1, NULL, producer, NULL);
    err = pthread_create(&c_tid1, NULL, consumer, NULL);
    err = pthread_create(&c_tid2, NULL, consumer, NULL);
    err = pthread_create(&p_tid2, NULL, producer, NULL);
    err = pthread_create(&c_tid3, NULL, consumer, NULL);
    err = pthread_create(&c_tid4, NULL, consumer, NULL);
    err = pthread_create(&c_tid5, NULL, consumer, NULL);
    error(err);//for sample
    err = pthread_join(p_tid1, tret);
    err = pthread_join(p_tid2, tret);
    err = pthread_join(c_tid1, tret);
    err = pthread_join(c_tid2, tret);
    err = pthread_join(c_tid3, tret);
    err = pthread_join(c_tid4, tret);
    err = pthread_join(c_tid5, tret);
    error(err);
    cout<<"everything is done! exit."<<endl;
    return 0;
}
