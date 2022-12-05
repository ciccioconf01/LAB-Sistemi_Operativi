#include <stdio.h>
#include <unistd.h>

int main(){
int i;
for (i=1; i<=2; i++) {
  if (!fork ())
    printf ("%d\n", i);
}
printf ("%d\n", i);

}
