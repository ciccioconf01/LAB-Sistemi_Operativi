#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define N_risorse 10
sem_t S1,ME1,ME2;
pthread_t id;
int risorse[N_risorse];

sem_init (&S1,0,N_risorse);
sem_init (&ME,0,1);


int request (){

    sem_wait(&s1);
    sem_wait(&ME);

    for(int i=0;i<N_risorse;i++){
        if(risorse[i]==0){
            risorse[i]=1;
            sem_wait(&ME);
            return i;
        }
    }

}

int relase (int i){

    sem_wait(&ME);
    risorse[i]=0;
    sem_post(&s1);
    sem_post(&ME);


}

