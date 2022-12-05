#include <stdio.h>

int main (){
	int n;
	scanf("%d",&n);
	while (n!=0){
		if (n%2==0){
			fprintf(stdout,"%d\n",n);			
			}
		else{
			fprintf(stderr,"%d\n",n);			
			}		
		scanf("%d",&n);
		
		}
		
}
