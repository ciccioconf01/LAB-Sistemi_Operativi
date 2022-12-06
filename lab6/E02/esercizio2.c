#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

typedef struct{
    char NomeIngresso[30];
    char NomeUscita[30];
    int i;
}arg;

void *funzione(arg *diz){

    char NomeInput[100];
    char NomeOutput[100]; 

    FILE *fin;
    FILE *fout;

    sprintf(NomeInput,"%s%d.txt",diz->NomeIngresso,diz->i+1);
    sprintf(NomeOutput,"%s%d.txt",diz->NomeUscita,diz->i+1);

    fin = fopen(NomeInput,"r");
    fout = fopen(NomeOutput,"w");

    int n;
    fscanf(fin,"%d",&n);
    int *vet;
    vet = malloc (n*sizeof(int));
    for(int i=0;i<n;i++){
        fscanf(fin,"%d",&vet[i]);
    }

    int comodo;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(vet[i]>vet[j]){
                comodo = vet[i];
                vet[i]=vet[j];
                vet[j]=comodo;
            }
        }
    }

    for(int i=0;i<n;i++){
        fprintf(fout,"%d\n",vet[i]);
    }

    free(vet);

    return;


}

int main(int argc,char **argv){

    int n = atoi(argv[1]);
    char NomeIngresso[20]; strcpy(NomeIngresso,argv[2]);
    char NomeUscita[20]; strcpy(NomeUscita,argv[3]);
    pthread_t id[n];

    arg diz[n];

    
    

    for(int i=0;i<n;i++){
        strcpy(diz[i].NomeIngresso,NomeIngresso);
        strcpy(diz[i].NomeUscita , NomeUscita);
        diz[i].i = i;
        pthread_create (&id[i],NULL,funzione, (void *) &diz[i]);
    }

    pthread_exit (NULL);
}