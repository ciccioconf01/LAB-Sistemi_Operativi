#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>

typedef struct{
    float c;
    float x;
    int n;
}monomio;

float val1, val2, val3;
int file;
int n;
sem_t S1; sem_t S2; sem_t S3; sem_t S4;
pthread_t T1; pthread_t T2; pthread_t T3; pthread_t T4;

void *PrimaLettura(){

    while(1){

        sem_wait(&S1);
        monomio m;
        float totale=1;
        n=read(file,&m,sizeof(monomio));
        if (n<=0){
            sem_post(&S2);
            break;
        }
        for(int i=0;i<m.n;i++){
            totale = totale * m.x;
        }
        val1 = totale + m.c;
        sem_post(&S2);
        }

        pthread_exit((void *) 1);
    
}

void *SecondaLettura(){

    while(1){

        sem_wait(&S2);
        monomio m;
        if (n<=0){
            sem_post(&S3);
            break;
        }
        
        int z=read(file,&m,sizeof(monomio));
        if (z<=0){
            m.c=0;
            m.x=0;
            m.n=0;
        }
        float totale=1;
        for(int i=0;i<m.n;i++){
            totale = totale * m.x;
        }
        val2 = totale + m.c;
        sem_post(&S3);
        }

        pthread_exit((void *) 1);
    
}

void *TerzaLettura(){

    while(1){

        sem_wait(&S3);
        monomio m;
        if (n<=0){
            sem_post(&S4);
            break;
        }
        
        int z=read(file,&m,sizeof(monomio));
        if (z<0){
            m.c=0;
            m.x=0;
            m.n=0;
        }
        float totale=1;
        for(int i=0;i<m.n;i++){
            totale = totale * m.x;
        }
        val3 = totale + m.c;
        sem_post(&S4);
        }

        pthread_exit((void *) 1);
    
}

void *Calcolo(){

    while(1){

        sem_wait(&S4);
        
        if (n<=0){
            break;
        }

        float totale = val1 + val2 + val3;
        printf("%f\n",totale);
        sem_post(&S1);
        }

        pthread_exit((void *) 1);
    
}


int main (int argc, char **argv){

    file = open(argv[1], O_RDONLY);

    sem_init(&S1,0,1);
    sem_init(&S2,0,0);
    sem_init(&S3,0,0);
    sem_init(&S4,0,0);
    pthread_create(&T1,NULL,PrimaLettura,NULL);
    pthread_create(&T2,NULL,SecondaLettura,NULL);
    pthread_create(&T3,NULL,TerzaLettura,NULL);
    pthread_create(&T4,NULL,Calcolo,NULL);

    pthread_join(T1,NULL);
    pthread_join(T2,NULL);
    pthread_join(T3,NULL);
    pthread_join(T4,NULL);
    
}