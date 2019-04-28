#include <stdio.h>
#include <stdlib.h>

int f(int n){

  //printf("f got called with n = %d \n", n);
  
  if(n < 2){
    return 2;
  } 


  return f(n-1) * 2;
}


int main(int argc, char *argv[]){

  int n;

  if(argc < 2){
    n = 4;
  } else { 
    n = atoi(argv[1]);
  }

  printf("f(%d) is %d\n\n", n, f(n));
  return 0;
}
