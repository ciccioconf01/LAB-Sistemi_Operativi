#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int SIG = 0;
int SIG1 = 0;
int SIG2 = 0;
int finish=0;

static void manager(int sig){
    if (sig == SIGUSR1){
        printf("segnale ricevuto da P1\n");
        SIG2 = SIG1;
        SIG1 = SIG;
        SIG = 1;

        printf ("%d %d %d\n",SIG, SIG1, SIG2);
    }
    if(sig == SIGUSR2){
        printf("segnale ricevuto da P2\n");
        SIG2 = SIG1;
        SIG1 = SIG;
        SIG = 2;

        printf ("%d %d %d\n",SIG, SIG1, SIG2);
    }

    if(SIG == SIG1 && SIG == SIG2){
        finish=1;
    }
}

int main(){
    int n;
    signal(SIGUSR1,manager);
    signal(SIGUSR2,manager);

        if(!fork()){
                //child1
                while (1){
                    n = rand()%2;
                    sleep (n);
                    kill(getppid(),SIGUSR1);
                }

                exit(0);
        }

        else if (!fork()){
            //child2
            while (1){
                    n = rand()%3;
                    sleep (n);
                    kill(getppid(),SIGUSR2);
                }
                exit(0);
            }

        // parent
        while (1){
            pause();
            if (finish==1){
                
                kill (0,SIGKILL);
                exit(0);
                }
            }
        }
            