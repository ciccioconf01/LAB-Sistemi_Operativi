#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

typedef struct{
    sem_t S1;
    sem_t S2;
    sem_t S3;
    sem_t S4;
    
}semaforo;

void B(semaforo *sem){

    sem_wait(&sem->S1);
    printf("B\n");
    sem_post(&sem->S4);
    //I(S1,S2,S3,S4);
    return;

}
void E(semaforo *sem){
    sem_wait(&sem->S2);
    printf("E\n");
    sem_post(&sem->S3);
    //G(S1,S2,S3,S4);
    return;
}
void G(semaforo *sem){
    sem_wait(&sem->S3);
    sem_wait(&sem->S3);
    printf("G\n");
    sem_post(&sem->S4);
    //I(S1,S2,S3,S4);
    return;
}
void F(semaforo *sem){
    sem_wait(&sem->S2);
    printf("F\n");
    sem_post(&sem->S3);
    
    return;
}

void C(semaforo *sem){
    sem_wait(&sem->S1);
    printf("C\n");
    sem_post(&sem->S2);
    sem_post(&sem->S2);

    
    return;
}




void I(semaforo *sem){
    sem_wait(&sem->S4);
    sem_wait(&sem->S4);
    sem_wait(&sem->S4);
    printf("I\n");
    return;
}
void DH(semaforo *sem){
    sem_wait(&sem->S1);
    printf("D\n");
    printf("H\n");
    sem_post(&sem->S4);
    
    return;
}



int main(){
    sem_t S1;
    sem_t S2;
    sem_t S3;
    sem_t S4;

    semaforo semafori;

    sem_init(&semafori.S1,0,0);
    sem_init(&semafori.S2,0,0);
    sem_init(&semafori.S3,0,0);
    sem_init(&semafori.S4,0,0);


    pthread_t id[5];
    

    while(1){

        printf("A\n");
        sem_post(&semafori.S1);
        sem_post(&semafori.S1);
        sem_post(&semafori.S1);
        pthread_create(&id[0],NULL,B,&semafori);
        pthread_create(&id[1],NULL,C,&semafori);
        pthread_create(&id[2],NULL,DH,&semafori);
        pthread_create(&id[3],NULL,E,&semafori);
        pthread_create(&id[4],NULL,F,&semafori);
        pthread_create(&id[5],NULL,G,&semafori);
        pthread_create(&id[6],NULL,I,&semafori);


    sleep(8);
    printf("\n");

    
}

}