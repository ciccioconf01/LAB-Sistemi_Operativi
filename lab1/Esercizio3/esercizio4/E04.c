#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){           
FILE *fp1,*fp2;
fp1=fopen(argv[1],"r");
fp2=fopen(argv[2],"w");

char tmp;

    while (fscanf(fp1,"%c",&tmp)!=EOF){
       
       fprintf(fp2,"%c",tmp);       
}

}
