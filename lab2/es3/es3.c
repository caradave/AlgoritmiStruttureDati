#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Corse{
    char codiceTratta[30];
    char partenza[30];
    char arrivo[30];
    int dd, mm, yyyy;
    int minPartenza, oraPartenza, secPartenza;
    int minArrivo, oraArrivo, secArrivo;
    int ritardo;
};

struct Corse *readFile(FILE *infile, struct Corse *corse, int *lenFile);
void output(FILE *infile, struct Corse *corse, int *lenCorse);
void printCorse(struct Corse *corse, int *lenCorse);
struct Corse *sortByDate(struct Corse *corse, int *lenCorse, struct Corse *corseSorted);
struct Corse *sortByCode(struct Corse *corse, int *lencorse, struct Corse *corseSorted);
struct Corse *sortByStartingStation(struct Corse *corse, int *lenCorse, struct Corse *corseSorted);
struct Corse *sortByEndingStation(struct Corse *corse, int *lenCorse, struct Corse *corseSorted);
void findByPartial(struct Corse *corse, int *lenCorse, char stazioneRicerca[]);
void findByPartialDicotomic(struct Corse *corse, int *lenCorse, char stazioneRicerca[]);
void findByPartialDicotomicUnwrap(struct Corse *corse, char stazioneRicerca[], int l, int r);

int main(void){
	FILE *infile = fopen("corse.txt", "r");
	int *lenFile;
	struct Corse *corse;

	if(infile == NULL){
		printf("errore nell'apetura del file\n");
		return -1;
	}

	output(infile, corse, lenFile);
	
	free(corse);
	fclose(infile);
	
	return 0;
}

struct Corse *readFile(FILE *infile, struct Corse *corse, int *lenFile){

	fscanf(infile, "%d", lenfile);

	for(int i=0; i<(*lenFile); i++)
		fscanf(infile, "%s %s %s %d/%d/%d %d:%d:%d %d:%d:%d %d", 
		corse[i].codiceTratta, 
		corse[i].partenza, 
		corse[i].arrivo, 
		&corse[i].yyyy, &corse[i].mm, &corse[i].dd, 
		&corse[i].oraPartenza, &corse[i].minPartenza, &corse[i].secPartenza, 
		&corse[i].oraArrivo, &corse[i].minArrivo, &corse[i].secArrivo,
		&corse[i].ritardo);
	return corse;
}

void printCorse(struct Corse *corse, int *lenCorse){
	for(int i=0; i<(*lenCorse); i++)
		printf("%s %s %s %02d/%02d/%02d %02d:%02d:%02d %02d:%02d:%02d %d\n", corse[i].codiceTratta, corse[i].partenza, corse[i].arrivo, corse[i].dd, corse[i].mm, corse[i].yyyy, corse[i].oraPartenza, corse[i].minPartenza, corse[i].secPartenza, corse[i].oraArrivo, corse[i].minArrivo, corse[i].secArrivo, corse[i].ritardo);
}

void output(FILE *infile, struct Corse *corse, int *lenCorse){

	corse = readFile(infile, corse, lenCorse);

	int selezione;
	char stazioneRicerca[30];
	char newFileName[30];
	FILE *newFilePointer;
	struct Corse *corseSortedData = malloc((*lenCorse)*sizeof(struct Corse));
	corseSortedData = sortByDate(corse, lenCorse, corseSortedData);
	struct Corse *corseSortedCodTratta = malloc((*lenCorse)*sizeof(struct Corse));
	corseSortedCodTratta = sortByCode(corse, lenCorse, corseSortedCodTratta);
	struct Corse *corseSortedStartingStation = malloc((*lenCorse)*sizeof(struct Corse));
	corseSortedStartingStation = sortByStartingStation(corse, lenCorse, corseSortedStartingStation);
	struct Corse *corseSortedEndingStation = malloc((*lenCorse)*sizeof(struct Corse));
	corseSortedEndingStation = sortByEndingStation(corse, lenCorse, corseSortedEndingStation);
	printf("1 se si desidera stampare a video i contenuti del file\n2 se si desidera ordinare il vettore di dati per data di partenza (a partità di data, per ora)\n3 se si desidera ordinare il vettore per codice di tratta\n4 se si desidera ordinare il vettore per stazione di partenza\n5 se si desidera ordinare il vettore per stazione di arrivo\n6 se si desidera cercare una stazione per nome parziale\n7 se si desidera ricercare una corsa per nome parziale della stazionen di partenza\n8 se si desidera immettere dei nuovi dati\nScelta: ");
	scanf("%d", &selezione);

	switch (selezione){
		case 1:
			printCorse(corse, lenCorse);
			break;
		case 2:
			printCorse(corseSortedData, lenCorse);
			break;
		case 3:
			printCorse(corseSortedCodTratta, lenCorse);
			break;
		case 4:
			printCorse(corseSortedStartingStation, lenCorse);
			break;
		case 5:
			printCorse(corseSortedEndingStation, lenCorse);
			break;
		case 6:
			printf("inserire il nome, anche parziale: ");
			scanf("%s", stazioneRicerca);
			findByPartial(corseSortedStartingStation, lenCorse, stazioneRicerca);
		break;
		case 7:
			printf("inserire il nome, anche parziale: ");
			scanf("%s", stazioneRicerca);
			findByPartialDicotomic(corseSortedStartingStation, lenCorse, stazioneRicerca);
		break;
		case 8:
			free(corse);
			struct Corse *corse;
			printf("inserire il nome del nuovo file");
			scanf("%s", newFileName);
			FILE *newFilePointer = fopen(newFileName, "r");
			readFile(newFilePointer, corse, lenCorse);
		break;
		default:
			printf("non è stato inserito un comando valido");
		break;
	}
	free(corseSortedData);
	free(corseSortedCodTratta);
	free(corseSortedStartingStation);
	free(corseSortedEndingStation);
}

struct Corse *sortByDate(struct Corse *corse, int *lenCorse, struct Corse *corseSorted){
	struct Corse temp;
	char iDate[10], kDate[10], iHour[10], kHour[10];
	
	for(int i=0; i<(*lenCorse); i++)
		corseSorted[i] = corse[i];

	for(int i=0; i<(*lenCorse); i++){
		sprintf(iDate, "%02d%02d%02d", corseSorted[i].yyyy, corseSorted[i].mm, corseSorted[i].dd);
		sprintf(iHour, "%02d%02d%02d", corseSorted[i].oraPartenza, corseSorted[i].minPartenza, corseSorted[i].secPartenza);
		for(int k=0; k<(*lenCorse); k++){
			sprintf(kDate, "%02d%02d%02d", corseSorted[k].yyyy, corseSorted[k].mm, corseSorted[k].dd);
			sprintf(kHour, "%02d%02d%02d", corseSorted[k].oraPartenza, corseSorted[k].minPartenza, corseSorted[k].secPartenza);
			if(strcmp(iDate, kDate) < 0){
				temp = corseSorted[k];
				corseSorted[k] = corseSorted[i];
				corseSorted[i] = temp;
			}else if(strcmp(iDate, kDate) == 0){
				if(strcmp(iHour, kHour) < 0){
					temp = corseSorted[k];
					corseSorted[k] = corseSorted[i];
					corseSorted[i] = temp;
				}
			}
		}
	}
	return corseSorted;
}

struct Corse *sortByCode(struct Corse *corse, int *lenCorse, struct Corse *corseSorted){
	for(int i=0; i<(*lenCorse); i++)
		corseSorted[i] = corse[i];

	for(int i=0; i<(*lenCorse); i++){
		for(int k=0; k<(*lenCorse); k++){
			if(strcmp(corseSorted[i].codiceTratta, corseSorted[k].codiceTratta)<0){
				struct Corse temp = corseSorted[k];
				corseSorted[k] = corseSorted[i];
				corseSorted[i] = temp;
			}
		}
	}
	return corseSorted;
}

struct Corse *sortByStartingStation(struct Corse *corse, int *lenCorse, struct Corse *corseSorted){

	for(int i=0; i<(*lenCorse); i++)
		corseSorted[i] = corse[i];

	for(int i=0; i<(*lenCorse); i++){
		for(int k=0; k<(*lenCorse); k++){
			if(strcmp(corseSorted[i].partenza, corseSorted[k].partenza)<0){
				struct Corse temp = corseSorted[k];
				corseSorted[k] = corseSorted[i];
				corseSorted[i] = temp;
			}
		}
	}
	return corseSorted;
}

struct Corse *sortByEndingStation(struct Corse *corse, int *lenCorse, struct Corse *sorted){
	struct Corse *corseSorted = malloc((*lenCorse)*sizeof(struct Corse));

	for(int i=0; i<(*lenCorse); i++)
		corseSorted[i] = corse[i];

	for(int i=0; i<(*lenCorse); i++){
		for(int k=0; k<(*lenCorse); k++){
			if(strcmp(corseSorted[i].arrivo, corseSorted[k].arrivo)<0){
				struct Corse temp = corseSorted[k];
				corseSorted[k] = corseSorted[i];
				corseSorted[i] = temp;
			}
		}
	}
	return corseSorted;
}

void findByPartial(struct Corse *corse, int *lenCorse, char stazioneRicerca[]){
	int lenStazione = strlen(stazioneRicerca);
	for(int i=0; i<(*lenCorse); i++){
		if(strncmp(corse[i].partenza, stazioneRicerca, lenStazione) == 0)
			printf("%s %s %s %02d/%02d/%02d %02d:%02d:%02d %02d:%02d:%02d %d\n", corse[i].codiceTratta, corse[i].partenza, corse[i].arrivo, corse[i].dd, corse[i].mm, corse[i].yyyy, corse[i].oraPartenza, corse[i].minPartenza, corse[i].secPartenza, corse[i].oraArrivo, corse[i].minArrivo, corse[i].secArrivo, corse[i].ritardo);
	}
}

void findByPartialDicotomic(struct Corse *corse, int *lenCorse, char stazioneRicerca[]){
	findByPartialDicotomicUnwrap(corse, stazioneRicerca, 0, (*lenCorse)-1);
}

void findByPartialDicotomicUnwrap(struct Corse *corse, char stazioneRicerca[], int l, int r){
	if(l >= r){
		if(strncmp(corse[l].partenza, stazioneRicerca, strlen(stazioneRicerca)) == 0){
			printf("%s %s %s %02d/%02d/%02d %02d:%02d:%02d %02d:%02d:%02d %d\n", corse[l].codiceTratta, corse[l].partenza, corse[l].arrivo, corse[l].dd, corse[l].mm, corse[l].yyyy, corse[l].oraPartenza, corse[l].minPartenza, corse[l].secPartenza, corse[l].oraArrivo, corse[l].minArrivo, corse[l].secArrivo, corse[l].ritardo);
		}
		return;
	}
	int m=(r+l)/2;
	findByPartialDicotomicUnwrap(corse, stazioneRicerca, l, m);
	findByPartialDicotomicUnwrap(corse, stazioneRicerca, m+1, r);
	return;
}
