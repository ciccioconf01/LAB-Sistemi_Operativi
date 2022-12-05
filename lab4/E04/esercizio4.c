#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

static void hendler(int signal){
	return;
}

int main(){
	pid_t pid;
	char stringa[20], stringa2[20];
	int i;
	FILE *fin,*fin2;
	signal (SIGUSR1,hendler);

	if(fork()!=0){
		wait((int*)0);
		}
	else{
		pid = fork();
		if(pid!=0){
			//produttore//
			
			while(1){
				fin = fopen("trasferimento.txt","w");
				printf("Inserisci la stringa:\n");
				scanf("%s",stringa);
				if(strcmp(stringa,"end")!=0){
					fprintf(fin,"%s",stringa);
					fclose(fin);
					kill(0,SIGUSR1);
					pause();				
					}
				else{
					fprintf(fin,"%s\n",stringa);
					fclose(fin);
					kill(0,SIGUSR1);
					exit(11);
					}
				}
			
					
			}
		else{
			//consumatore
			while(1){
				pause();
				sleep(2);
				fin = fopen("trasferimento.txt","r");
				fscanf(fin,"%s",stringa2);
				if(strcmp(stringa2,"end")==0){
					exit(11);
					}
				i=0;
				char x = 'a' - 'A';
				while(stringa2[i]!='\0'){
					stringa2[i] = stringa2[i] - x;
					fprintf(stdout,"%c\n",stringa2[i]);
					i++;
					}
				fclose(fin);	
				kill(0,SIGUSR1);			
				}
			
			}
		}
	
}
