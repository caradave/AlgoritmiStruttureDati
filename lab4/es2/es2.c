#include <stdio.h>
#include <stdlib.h>

#define maxC  50


// data structure
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


//functions
struct Node *newNode(struct Node *node, struct Persona persona);
struct Node *readFile(FILE *infile, struct Node *head);
void freeList(struct Node *head);
void printList(struct Node *head);
struct Node *sortList(struct Node *head);
struct Node *addElement(struct Node *head);
int compareDate(struct Data i, struct Data k);


// main
int main(void){
	struct Node *head = malloc(sizeof(struct Node));
	FILE *infile = fopen("anag1.txt", "r");
	
	if(infile == NULL){
		printf("impossibile aprire il file");
		return -1;
	}


	head = readFile(infile, head);
	head = sortList(head);
	printList(head);

	fclose(infile);
	freeList(head);
	return 0;
}


//functions' body
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
	struct Node *node = head->next;
	while(node != NULL){
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

int compareDate(struct Data i, struct Data k){
	if((i.anno*10000 + i.mese*100 + i.giorno) > (k.anno*10000 + k.mese*100 + k.giorno))
		return 1;
	return 0;
}

struct Node *sortList(struct Node *head){
	struct Node *current = malloc(sizeof(struct Node));
	struct Node *last = NULL;
	int bool = 1;
	do {
		bool = 0;
		current = head;

		while (current->next != last) {
			if (compareDate(current->persona.nascita, current->next->persona.nascita)) {
				struct Persona temp = current->persona;
				current->persona = current->next->persona;
				current->next->persona = temp;
				bool = 1;
			}
			current = current->next;
		}
		last = current;
	} while (bool);
	return head;
}

struct Node *addElement(struct Node *head){
	struct Persona personaAdd;
	struct Node *temp = head;
	int bool = 0;

	scanf("%s %s %s %d/%d/%d %s %s %d", personaAdd.codice, personaAdd.nome, personaAdd.cognome, &personaAdd.nascita.giorno, &personaAdd.nascita.mese, &personaAdd.nascita.anno, personaAdd.via, personaAdd.citta, &personaAdd.cap);

	if(compareDate(temp->persona.nascita, personaAdd.nascita)){
		newNode(head, personaAdd);
		bool = 1;	
	}

	while(compareDate(temp->next->persona.nascita, personaAdd.nascita) && temp->next != NULL && bool == 0)
		temp = temp->next;

	struct Node *newNodeToAdd = malloc(sizeof (struct Node));
	newNodeToAdd->persona = personaAdd;
	newNodeToAdd->next = temp->next;
	temp->next = newNodeToAdd;

	return head;
}
