#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *cercaRegexp(char *src, char *regexp);

int main(void){
  char *src = malloc(10*sizeof(char));
  char *regexp = malloc(40*sizeof(char));

  strcpy(src, "ciciao");
  strcpy(regexp, ".\\Ci[^skjhfgskj][kjfhgko]");

  printf("%s\n", cercaRegexp(src, regexp));

  free(src);
  free(regexp);
  
  return 0;
}


char *cercaRegexp(char *src, char *regexp){
  int srcLen = strlen(src), regexpLen = strlen(regexp);
  int k = 0, findTrue = 0;

  char *result = malloc(srcLen*sizeof(char));
  int resultLen = 0;

  for(int i=0; i<srcLen &&  findTrue == 0; i++){
    findTrue = 1;
    k = 0;

    while(k < regexpLen && findTrue == 1){
      printf("regexp: %c, src: %c ", regexp[k], src[i+resultLen]);
      findTrue = 0;
      switch (regexp[k]){
        case '.':
          findTrue=1;
          k++;
        break;
        case '[':
          k++;
          if(regexp[k] != '^'){
            while(regexp[k] != ']'){
              if(regexp[k] == src[i+resultLen])
                findTrue = 1;
              k++;
            }
            k++;
          }else{
            k++;
            findTrue = 1;
            while(regexp[k] != ']'){
              if(regexp[k] == src[i+resultLen])
                findTrue = 0;
              k++;
            }
            k++;
          }
        break;
        case '\\':
          k++;
         if(islower(regexp[k]) && islower(src[i]))
            findTrue = 1;
          else if(!islower(regexp[k]) && !islower(src[i]))
            findTrue = 1;
          else
            findTrue = 0;
          k++;
        break;
        default:
          if(regexp[k] == src[i+resultLen]){
            findTrue = 1;
            k++;
          }else{
            k=0;
          }
      
      }
      if(findTrue == 1){
        result[resultLen] = src[i+resultLen];
        resultLen++;
      }else{
        strcpy(result, "");
        resultLen = 0;
      }
      printf("%s\n", result);
    }
    printf("\n");
  }
  return result;
}
