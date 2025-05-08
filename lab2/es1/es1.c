#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int gcd(int a, int b);

int main(void){
  int a, b;
  srand(time(NULL));
  
  for(int i=0; i<10; i++){
    a = rand()%30;
    b = rand()%30;
    printf("a: %d, b: %d, gcd: %d\n", a, b, gcd(a, b));
  }

  return 0;
}

int gcd(int a, int b){
  if(a < b){
    int temp = a;
    a = b;
    b = temp;
  }
  if(a%b == 0)
    return b;
  else{
    if (a%2 == 0 && b%2 == 0)
      return 2*gcd(a/2, b/2);
    if(a%2 != 0 && b%2 == 0)
      return gcd(a, b/2);
    else if(a%2 != 0 && b%2 != 0)
        return gcd((a-b)/2, b);
    return 1;
  }
}
