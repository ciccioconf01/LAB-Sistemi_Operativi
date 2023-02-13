#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t Sa,Sb;

void *A(int *i){

    int num=*i; 

    sem_wait(&Sa);
    printf("A%d ",num);
    sem_post(&Sb);

    pthread_exit((void *) 0);

}

void *B(int *i){

    int num=*i;

    sem_wait(&Sb);
    printf("B%d\n",num);
    sem_post(&Sa);

    pthread_exit((void *) 0);
    
}

int main(int argc , char **argv){
    int n=atoi(argv[1]);
    pthread_t idA[n];
    pthread_t idB[n];

    sem_init(&Sa,0,1);
    sem_init(&Sb,0,0);

    int vet[n];

    for(int i=0;i<n;i++){
        vet[i]=i;
    }

    for(int i=0;i<n;i++){
        pthread_create(&idA[i],NULL,A,&vet[i]);
        pthread_create(&idB[i],NULL,B,&vet[i]);
    }

    pthread_exit((void *) 0);

}