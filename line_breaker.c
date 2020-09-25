#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char ori[20];
  FILE *in, *out;
  int read=1, i=0;
  in = fopen("nomes", "r"); //NAME OF THE INPUT FILE HERE
  out = fopen("nomes_lb", "w"); //NAME OF THE OUTPUT FILE HERE
  while (read!=EOF){
    for (i=0;i<20;i++) ori[i]='\0';
    read = fscanf(in, "%s", ori);
    fprintf(out, "%s\n", ori);
  }
  return 0;
}
