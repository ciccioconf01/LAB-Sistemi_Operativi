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


int main(int argc, char **argv){
    FILE *fin;
    int file;
    monomio m;
    fin = fopen(argv[1],"r");

    file = creat(argv[2],0666);
    while(fscanf(fin,"%f %f %d",&m.c,&m.x,&m.n)!=EOF){
        write(file,&m,sizeof(monomio));
    }

    fclose(fin);
    close(file);

    file = open(argv[2], O_RDONLY);

    while(read(file,&m,sizeof(monomio))>0){
        printf("%f %f %d\n",m.c,m.x,m.n);
    }


}