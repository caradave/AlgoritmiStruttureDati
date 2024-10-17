#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Persona{
	char canzoni[5][255];
	int numCanzoni;
};

struct Persona *leggiFile(struct Persona *persone, FILE *infile, int *lenFile);
void princ_molt(int pos, struct Persona *val, char sol[][255], int n);


int main(void){
	FILE *infile = fopen("brani.txt", "r");
	int *lenFile = malloc(sizeof(int));
	struct Persona *persone = leggiFile(persone, infile, lenFile);
	
	char sol[*lenFile][255];

	princ_molt(0, persone, sol, *lenFile);

	fclose(infile);
	return 0;
}

struct Persona *leggiFile(struct Persona *persone, FILE *infile, int *lenFile){
	int numCanzoni;
	char canzone[255];

	fscanf(infile, "%d\n", lenFile);
	persone = (struct Persona *)malloc(*lenFile * sizeof(struct Persona));
	
	for(int i=0; i<*lenFile; i++){
		fscanf(infile, "%d\n", &numCanzoni);
		persone[i].numCanzoni = numCanzoni;
		for(int k=0; k<numCanzoni; k++){
			fscanf(infile, "%s", canzone);
			strcpy(persone[i].canzoni[k], canzone);
		}
	}

	return persone;
}

void princ_molt(int pos, struct Persona *val, char sol[][255], int n) {
	int i;
	if (pos >= n) {
		for (i = 0; i < n; i++)
			printf("%s ", sol[i]);
		printf("\n");
		return;
	}
	
	for (i = 0; i < val[pos].numCanzoni; i++) {
	strcpy(sol[pos], val[pos].canzoni[i]);
		princ_molt(pos+1, val, sol, n);
	}
	return;
}
