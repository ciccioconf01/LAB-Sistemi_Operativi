#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <string.h>


FILE *fin;
FILE *fout;
char line[100];
sem_t S1; sem_t S2; sem_t S3;
pthread_t idA;  pthread_t idB;  pthread_t idC;

void *leggi();
void *inverti();
void *scrivi();


int main(int argc, char **argv){
    
    fin = fopen(argv[1],"r");
    fout = fopen(argv[2],"w");
    
    
    sem_init(&S1,0,1);   
    sem_init(&S2,0,0); 
    sem_init(&S3,0,0); 

    pthread_create(&idA,NULL,leggi,NULL);
    pthread_create(&idB,NULL,inverti,NULL);
    pthread_create(&idC,NULL,scrivi,NULL);

    pthread_join(idA,NULL);
    pthread_join(idB,NULL);
    pthread_join(idC,NULL);

    return 0;


}

void *leggi(){
    int goON=0;

    while(goON==0){
        sem_wait(&S1);
        
    
        if(fgets(line,100,fin)==NULL){
            goON=1;
            strcpy(line,"esci");
        }

        sem_post(&S2);
       
    }

    pthread_exit((void *) 1);

    

}

void *inverti(){
    int goON=0;
    while(goON==0){
        sem_wait(&S2);
        
        
        char StringaInvertita[100];
        int z=0;
        int dif = 'a' - 'A';
        if(strcmp("esci",line)==0){
            goON=1;
            sem_post(&S3);
        }
        else{
            for(int i=strlen(line)-1;i>=0;i--){

                if(line[i]>='a' && line[i]<='z'){
                    line[i]=line[i] - dif;
                }
                StringaInvertita[z]=line[i];
                z++;
        }



        strcpy(line,StringaInvertita);
        sem_post(&S3);

        }
        


        
    }

    pthread_exit((void *) 1);
    

}

void *scrivi(){
    int goON=0;
    while(goON==0){
        sem_wait(&S3);
        if(strcmp("esci",line)==0){
            goON=1;
        }
        else{
            fprintf(fout,"%s\n",line);
            sem_post(&S1);
        }

        
    }

    pthread_exit((void *) 1);
    

}