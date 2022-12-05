#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void funzione(){

printf("P3\n");

if(fork()){
	wait((int *)0);
}

else{
	printf("P6\n");
	sleep(1);
	exit(2);
}
printf("P8\n");
}


int main(){

printf("P1\n");
if (fork()){
       wait((int *)0);
        printf("P2\n");
        if(fork()){
              printf("P4\n");
                   wait((int *)0);

                 }
        else{
             printf("P5\n");
             sleep(1);
             exit(2);
                 }
        printf("P7\n");
        }
else{
      funzione();
	sleep(1);
	exit(1);
	}
printf("P9\n");
}
