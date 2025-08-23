#include <stdio.h>

int check(int *sol, int k){
  int count = 1;
  for(int i=0; i<k; i++)
    if(sol[i] == count)
      count ++;
  if(count == 5)
    return 1;
  return -1;
}

void printSol(int *sol, int k){
  for(int i=0; i<k; i++){
    switch (sol[i]){
      case 1:
      printf("A");
      break;
      case 2:
      printf("E");
      break;
      case 3:
      printf("I");
      break;
      case 4:
      printf("O");
      break;
      case 5:
      printf("U");
      break;
    }
  }
}

void disp_rip(int *val, int *sol, int pos, int n, int k){
  if(pos >= k){
    if(check(sol, k) == 1)
      printSol(sol, k);
    return;
  }
  for(int i=0; i<n; i++){
    sol[pos] = val[i];
    disp_rip(val, sol, pos+1, n, k);
  }
  return;
}

