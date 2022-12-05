#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>


int main(){
	int fin;
	char nome[10] = {"input.txt"};
    int vet[10] = {0,5,7,4,6,8,9,1,2,3};
	fin = creat(nome, 0666);
    
    for(int i = 0; i < 10; i++){
        write(fin, &vet[i], sizeof (int));
    }
    close(fin);

	
	fin = open (nome, O_RDWR);
	
	int elem = 10;
	int v1,v2,pid;
	
	for (int i =0;i<elem-1;i++){
		for (int j =0;j<elem-1-i;j++){
			pid=fork();
			if (pid!=0){
				wait((int *)0);				
				}
			else{
				lseek(fin,j*sizeof(int),SEEK_SET);
				read(fin,&v1,sizeof(int));		
				lseek(fin,(j+1)*sizeof(int),SEEK_SET);
				read(fin,&v2,sizeof(int));	
				if(v1>v2){
						lseek(fin,j*sizeof(int),SEEK_SET);
						write(fin,&v2,sizeof(int));	
						lseek(fin,(j+1)*sizeof(int),SEEK_SET);
						write(fin,&v1,sizeof(int));				
					}	
				exit(1);	
				}			
			}		
		}
	close(fin);

	fin = open (nome, O_RDONLY);
	for (int i=0;i<elem;i++){
		lseek(fin,i*sizeof(int),SEEK_SET);
		read(fin,&v1,sizeof(int));
		printf("%d",v1);	
		}
	close(fin);
	
	}
