#include <stdio.h>
#include <stdlib.h>

int majority(int *vet, int len);
int majorityR(int *vet, int l, int r, int element);
int checkEffectiveMajo(int *vet, int l, int r, int element);

int main(void){
  FILE *infile = fopen("test.txt", "r");
  
  char string[30];
  int *vet = malloc(10*sizeof(int));
  
  if(infile == NULL){
    printf("impossibile aprire il file");
    return -1;
  }

  while(fscanf(infile, "%s\n", string) == 1){
    sscanf(string, "%d,%d,%d,%d,%d,%d,%d\n", &vet[0], &vet[1], &vet[2], &vet[3], &vet[4], &vet[5], &vet[6]);
    printf("%d, %d, %d, %d, %d, %d, %d. maggioritario: ", vet[0], vet[1], vet[2], vet[3], vet[4], vet[5], vet[6]);
    printf("%d \n", majority(vet, 7));
  }

  
  free(vet);
  fclose(infile);
  return 0;
}


int majority(int *vet, int len){
  
  return majorityR(vet, 0, len-1, -1);

}


int majorityR(int *vet, int l, int r, int element){
  if(l == r){
    return vet[l];
  }
  
  int mid = (l+r)/2;

  int left = majorityR(vet, l, mid, element);
  int right = majorityR(vet, mid+1, r, element);

  if(left == right)
    return right;

  int countLeft = checkEffectiveMajo(vet, l, r, left);
  int countRight = checkEffectiveMajo(vet, l, r, right);

  if(countLeft > (r-l+1)/2)
    return left;
  else if(countRight > (r-l+1)/2)
    return right;
  return -1;
}

int checkEffectiveMajo(int *vet, int l, int r, int element){
  int occurences = 0;

  for(int i=l; i<=r; i++)
    if(vet[i] == element){
      occurences++;
    }

  return occurences;

}
