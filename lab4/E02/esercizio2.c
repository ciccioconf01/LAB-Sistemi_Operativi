#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>


int main(){
	int fin;
	fin = open ("input.txt, O_RDWR);
	
	int elem = 5,v1,v2,pid;
	
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
						write(fin,&v2,sizeof(int);	
						lseek(fin,(j+1)*sizeof(int),SEEK_SET);
						write(fin,&v1,sizeof(int);				
					}	
				exit(11);	
				}			
			}		
		}
	fclose(fin);
	}
