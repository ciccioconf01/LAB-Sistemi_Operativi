#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE *fin;
	char stringa[50];
	fin = fopen("file1.txt","r");
	while(!feof(fin)){
		fgets(stringa,50,fin);
		system(stringa);
	}
}
