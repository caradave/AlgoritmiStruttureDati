#include <stdio.h>
#include <stdlib.h>

#define maxC  50

struct Data{
	int giorno, mese, anno;
};

struct Persona{
	struct Data nascita;
	char codice[maxC], nome[maxC], cognome[maxC], via[maxC], citta[maxC];
	int cap;
};

struct Node{
	struct Persona persona; 

	struct Node *next;
};

struct Node *newNode(struct Node *node, struct Persona persona);
struct Node *readFile(FILE *infile, struct Node *head);
void freeList(struct Node *head);
void printList(struct Node *head);
struct Node *sortList(struct Node *head);

int main(void){
	struct Node *head = malloc(sizeof(struct Node));
	FILE *infile = fopen("anag1.txt", "r");
	
	if(infile == NULL){
		printf("impossibile aprire il file");
		return -1;
	}


	head = readFile(infile, head);
	printList(head);

	fclose(infile);
	freeList(head);
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

void printList(struct Node *head){
	struct Node *node = head;
	while(node -> next != NULL){
		printf( "%s %s %s %d/%d/%d %s %s %d\n", node->persona.codice, node->persona.nome, node->persona.cognome, node->persona.nascita.giorno, node->persona.nascita.mese, node->persona.nascita.anno, node->persona.via, node->persona.citta, node->persona.cap);
		node = node->next;
	}
}

struct Node *readFile(FILE *infile, struct Node *head){
	struct Persona persona;
	while((fscanf(infile, "%s %s %s %d/%d/%d %s %s %d", persona.codice, persona.nome, persona.cognome, &persona.nascita.giorno, &persona.nascita.mese, &persona.nascita.anno, persona.via, persona.citta, &persona.cap)) != EOF){
	//	printf("%s %s %s %d/%d/%d %s %s %d", persona.codice, persona.nome, persona.cognome, persona.nascita.giorno, persona.nascita.mese, persona.nascita.anno, persona.via, persona.citta, persona.cap);
		head = newNode(head, persona);
	}
	return head;
}

void freeList(struct Node *head){
	if(head->next != NULL){
		freeList(head->next);
	}
	free(head);
	return;
}

struct Node *sortList(struct Node *head){
	
}
