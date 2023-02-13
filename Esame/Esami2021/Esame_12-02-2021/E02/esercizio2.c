#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <string.h>

sem_t ME,S1,S2;

sem_init(&ME,0,1);
sem_init(&ME,0,0);
sem_init(&ME,0,0);

char stato[10];

int bloccatiRed;
int bloccatiGreen;

void red(){

    if(strcmp(stato,"red")!=0){
        bloccatiRed++;
        sem_wait(&S1);
    }

    printf("red");


}

void green(){

    if(strcmp(stato,"green")!=0){
        bloccatiGreen++;
        sem_wait(&S2);
    }

    printf("green");


}

void change (){

    sem_wait(&ME);
    if(strcmp(stato,"red")==0){

        strcpy(stato,"green");
        for(int i=0;i<bloccatiGreen;i++){
            sem_post(&S2);
        }
        bloccatiGreen=0;
    }

    else{
        strcpy(stato,"red");
        for(int i=0;i<bloccatired;i++){
            sem_post(&S1);
        }
        bloccatired=0;
    }
    sem_post(&ME);
}