#include <stdio.h>
#include <stdlib.h>

#define maxC  50

struct Data{
	int giorno, mese, anno;
};

struct Persona{
	struct Data nascita;
	char nome[maxC], cognome[maxC], via[maxC], citta[maxC];
	int cap;
};

struct Node{
	struct Persona persona; 

	struct Node *next;
};

struct Node *newNode(struct Node *node, struct Persona persona);
void readFile(FILE *infile, struct Node *node);


int main(void){
	FILE *infile = fopen("anag1.txt", "r");
	struct Node *head = malloc(sizeof(struct Node));

	readFile(infile, head);


	fclose(infile);
	return 0;
}

struct Node *newNode(struct Node *node, struct Persona persona){
	struct Node *x = malloc(sizeof(* x));
	if(x == NULL)
		return NULL;
	else{
		x->persona = persona;
		x->next = node;
	}
	return x;
}


void readFile(FILE *infile, struct Node *node);
