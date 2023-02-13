#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t Sa,Sb,ME;

sem_init(&Sa,0,0);
sem_init(&Sb,0,0);

void *A(){
    sem_post(&Sb);
    sem_wait(&Sa);

}

void *B(){

    sem_post(&Sa);
    sem_wait(&Sb);

}

