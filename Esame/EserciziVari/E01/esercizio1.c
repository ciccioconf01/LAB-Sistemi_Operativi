#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct record_s{

    int i;
    char s[50];
    float f;

} record_t;

int main(){

    int fd;
    record_t dizionario[30];
    char c;
    char *line;
    int pos = 0;
    int i = 0;
    int not_end;

    fd = open("testo.txt",O_RDONLY);

    do{
        line = malloc (50*sizeof(char));

        do{
            not_end = read(fd,&c,sizeof (char));
            if (not_end!=0){
                line[pos]=c;
                pos++;
            }
            
        }while (c!='\n');

        if(not_end!=0){
            
            sscanf(line,"%d %s %f",&dizionario[i].i,dizionario[i].s,&dizionario[i].f);
            i++;
            pos=0;
        }
        
        free(line);
    }while (not_end!=0);


    for (int j=0;j<i;j++){
        printf("%d %s %f\n",dizionario[j].i,dizionario[j].s,dizionario[j].f);
    }

}