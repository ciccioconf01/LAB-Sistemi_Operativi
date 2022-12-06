#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define nElem 6 


void *funzione(int *vet){

    int comodo;
    for(int i=0;i<nElem-1;i++){
        for(int j=i+1;j<nElem;j++){
            if(vet[i]>vet[j]){
                comodo = vet[i];
                vet[i]=vet[j];
                vet[j]=comodo;
            }
        }
    }
    return;
}

void lentini(int *vet,int n){

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
    return;
}

int main(int argc,char **argv){

    int n = atoi(argv[1]);
    char NomeIngresso[20]; strcpy(NomeIngresso,argv[2]);
    char NomeUscita[20]; strcpy(NomeUscita,argv[3]);
    pthread_t id[n];

    int mat[n][nElem];

    FILE *fin;
    FILE *fout;

    fout = fopen(NomeUscita,"w");
    char NomeIn[200];
    for (int i=0;i<n;i++){
        sprintf(NomeIn,"%s%d.txt",NomeIngresso,i+1);

        fin = fopen(NomeIn,"r");

        for(int j=0;j<nElem;j++){
            fscanf(fin,"%d",&mat[i][j]);
        }
    }
    
    int VetF[n*nElem]; int z; int j=0;

    for(int i=0;i<n*nElem;i++){

        VetF[i]=10000000;

    }

    for(int i=0;i<n;i++){
        
        pthread_create (&id[i],NULL,funzione, (void *) &mat[i]);
        pthread_join (id[i], NULL);

        z=0;
        for( j = i*nElem;j<i*nElem+nElem;j++ ){
            VetF[j] = mat[i][z];
            z++;
        }
        lentini(VetF,j);
        
    }

    for(int i=0;i<n*nElem;i++){

        fprintf(fout,"%d\n",VetF[i]);

    }

}