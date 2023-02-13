#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int fd[2];

void init(){
    if (pipe(fd)==-1){
        printf("errore nella creazione della pipe");
        exit(1);
    }

    return;

}
void wait(){
    char c;
    if(read(fd[0],&c,1)!=1){
        printf("errore");
        exit(1);
    }

    return;

}


void signal(){
    char c='x';
    if(write(fd[1],&c,1)!=1){
        printf("errore");
        exit(1);
    }

    return
}