#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

static void messaggio(int sig){

		if(sig == SIGUSR2){
			printf("FATHER WOKE UP\n");
			
			}
		else{
			printf("CHILD WOKE UP\n");			
			}
		return;

}

int main(){
		
	signal(SIGUSR2,messaggio);
	signal(SIGUSR1,messaggio);

	for(int i=0;i<5;i++){
		if(fork()!=0){
			sleep(1);
			kill(getpid(),SIGUSR2);
			wait((int*)0);
			}
		else{
			kill(getpid(),SIGUSR1);

			exit(11);			
			}
						
		}
	
}
