#ifndef LIST_H
#define LIST_H

#include "esercizio.h"
#include <stdio.h>
#include <stdlib.h>

#define LEND 3
#define DP 20
#define DD 10

typedef struct Node{
  Exercise **e;
  int lenE;
  int diff;
  int mark;
  struct Node *next;
} Node;

struct Node *newNode(Exercise **e, int lenE, int diff, struct Node *h);
void printList(struct Node *h);
struct Node **createVett(struct Node *h, struct Node **vett);
struct Node **allocateVett(int len);
void printVett(struct Node **vett, int len);
int getLenLinkedList(struct Node *h);

int checkDiffDiag(struct Node *n);
int checkProgDiff(struct Node **vett);
float countValueDiag(struct Node **vett);
int checkAcroProg(struct Node **vett);
int checkFinal(struct Node *n);
int checkPrec(struct Node *n);
int checkAcroSeq(struct Node **vett);
 
#endif
