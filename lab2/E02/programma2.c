#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(){
int n, t;

pid_t pid,pid2;

printf("Inserisci n: ");
scanf("%d",&n);
printf("\nInserisci t: ");
scanf("%d",&t);

for (int i=0;i<n;i++){
	
	pid = fork();
	if (pid!=0){
		pid2=fork();
			if(pid2!=0){
				exit(11);
				}
		
		}
}

sleep (t);
printf("il processo e' terminato\n");
}
