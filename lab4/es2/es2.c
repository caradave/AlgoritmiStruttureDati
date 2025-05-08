#include <stdio.h>
#include <stdlib.h>
#include "persone.h"

#define MAXC 50

typedef struct Node{
  Persone *persona;
  struct Node *next;
} Node;

struct Node *newNode(struct Node *h, Persone *p);
struct Node *readFile(FILE *infile, struct Node *h);
struct Node *sortList(struct Node *h);
void printList(struct Node *h);
struct Node *addInOrder(struct Node *h, Persone *p);
Persone *removeNode(struct Node *node);
Persone *removeNodeByCode(struct Node *h, char *cod);

int main(void){
  FILE *infile = fopen("anag1.txt", "r");

  if(infile == NULL){
    printf("impossibile aprire il file");
    return 0;
  }  
  struct Node *head = NULL;
  head = readFile(infile, head);
  printList(head);

  printf("\n");
  head = sortList(head);
  printList(head);

  fclose(infile);
  return 0;
}

struct Node *newNode(struct Node *h, Persone *p){
  struct Node *x = malloc(sizeof(struct Node));

  if(x == NULL)
    return NULL;
  else{
    x->persona = p;
    x->next = h;
  }
  return x;
}

void printList(struct Node *h){
  for(struct Node *temp=h; temp!=NULL; temp=temp->next){
    printPersona(temp->persona);
  }
}

struct Node *readFile(FILE *infile, struct Node *h){
  char *string = malloc(200*sizeof(char));
  Persone *p;

  while(fgets(string, 200*sizeof(char), infile)){
    p = createPersone(p, string);
    h = newNode(h, p);
  }

  free(string);
  return h;
}

struct Node *addInOrder(struct Node *h, Persone *p){
  if(h == NULL || comparaDataNascita(h->persona, p) < 1)
    return newNode(h, p);

  struct Node *i=h->next, *x=h;
  for(; i!=NULL && comparaDataNascita(i->persona, p) == 1; i=i->next, x=x->next);
  
  struct Node *k=malloc(sizeof(struct Node));
  k->persona = p;
  k->next = i;
  x->next = k;

  return h;
}

struct Node *sortList(struct Node *h){
  int checkSorted=1;
  
  struct Node *newHead = NULL;
  for(struct Node *p=h; p != NULL; p=p->next){
    newHead = addInOrder(newHead, p->persona);
    printList(newHead);
    printf("\n");
  }

  return newHead;
}

Persone *removeNodeByCode(struct Node *h, char *cod){
  struct Node *i=h->next, *x=h;
  
  if(comparaCodice(h->persona, cod) == 0){
    Persone *p = h->persona;
    h = h->next;
    return p;
  }

  for(; i!=NULL && comparaCodice(i->persona, cod) == 0; i=i->next, x=x->next);

  return removeNode(x);
}

Persone *removeNode(struct Node *node){
  Persone *p = node->next->persona;

  node->next = node->next->next;

  return p;
}

