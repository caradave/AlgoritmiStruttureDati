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

void printData(struct  Corse *corse, int lenCorse);
void output(struct Corse *corse, int lenCorse);
void sortByDate(struct Corse *corse, int lenCorse);
void sortByCode(struct Corse *corse, int lencorse);
void sortByDeparture(struct Corse *corse, int lencorse);
void sortByArrival(struct Corse *corse, int lencorse);



int main(void){
    FILE *infile = fopen("corse.txt", "r");
    int lenFile;

    if(infile == NULL){
        printf("errore nell'apertura del file\n");
        return -1;
    }

    fscanf(infile, "%d", &lenFile);
    struct Corse *corse = malloc(lenFile*sizeof(struct Corse));

    for(int i=0; i<lenFile; i++){
        fscanf(infile, "%s %s %s %d/%d/%d %d:%d:%d %d:%d:%d %d",
               corse[i].codiceTratta,
               corse[i].partenza,
               corse[i].arrivo,
               &corse[i].yyyy, &corse[i].mm, &corse[i].dd,
               &corse[i].oraPartenza, &corse[i].minPartenza, &corse[i].secPartenza,
               &corse[i].oraArrivo, &corse[i].minArrivo, &corse[i].secArrivo,
               &corse[i].ritardo);
        //        printf("%s %s %s %d/%d/%d %d:%d:%d %d:%d:%d %d\n", corse[i].codiceTratta, corse[i].partenza, corse[i].arrivo, corse[i].dd, corse[i].mm, corse[i].yyyy, corse[i].oraPartenza, corse[i].minPartenza, corse[i].secPartenza, corse[i].oraArrivo, corse[i].minArrivo, corse[i].secArrivo, corse[i].ritardo);
    }
    output(corse, lenFile);
    free(corse);
    fclose(infile);
    printf("sono qui");
    return 0;
}

void output(struct Corse *corse, int lenCorse){
    int selezione;
    printf("1 se si desidera stampare a video i contenuti del file\n2 se si desidera ordinare il vettore di dati per data di partenza (a partità di data, per ora)\n3 se si desidera ordinare il vettore per codice di tratta\n4 se si desidera ordinare il vettore per stazione di partenza\n5 se si desidera ordinare il vettore per stazione di attivo\n6 se si desidera cercare una stazione per nome parziale\nScelta: ");
    scanf("%d", &selezione);

    switch (selezione){
        case 1:
            printData(corse, lenCorse);
            break;
        case 2:
            sortByDate(corse, lenCorse);
            break;
        case 3:
            sortByCode(corse, lenCorse);
            break;
        case 4:
            sortByDeparture(corse, lenCorse);
            break;
        case 5:
            sortByArrival(corse, lenCorse);
            break;
        default:
            printf("Il numero inserito non è valido");
            break;
    }
}

void sortByDate(struct Corse *corse, int lenCorse){
    struct Corse *corseSorted = malloc(lenCorse*sizeof(struct Corse));
    struct Corse temp;
    char iDate[10], kDate[10], iHour[10], kHour[10];

    for(int i=0; i<lenCorse; i++)
        corseSorted[i] = corse[i];

    for(int i=0; i<lenCorse; i++){
        sprintf(iDate, "%02d%02d%02d", corseSorted[i].yyyy, corseSorted[i].mm, corseSorted[i].dd);
        sprintf(iHour, "%02d%02d%02d", corseSorted[i].oraPartenza, corseSorted[i].minPartenza, corseSorted[i].secPartenza);
        for(int k=0; k<lenCorse; k++){
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
    printData(corseSorted, lenCorse);
    free(corseSorted);
}

void sortByCode(struct Corse *corse, int lenCorse){
    struct Corse *corseSorted = malloc(lenCorse*sizeof(lenCorse));

    for(int i=0; i<lenCorse; i++)
        corseSorted[i] = corse[i];

    for(int i=0; i<lenCorse; i++){
        for(int k=0; k<lenCorse; k++){
            if(strcmp(corseSorted[i].codiceTratta, corseSorted[k].codiceTratta)<0){
                struct Corse temp = corseSorted[k];
                corseSorted[k] = corseSorted[i];
                corseSorted[i] = temp;
            }
        }
    }
    printData(corseSorted, lenCorse);
    free(corseSorted);
}

void sortByDeparture(struct Corse *corse, int lenCorse){
    struct Corse *corseSorted = malloc(lenCorse*sizeof(lenCorse));

    for(int i=0; i<lenCorse; i++)
        corseSorted[i] = corse[i];

    for(int i=0; i<lenCorse; i++){
        for(int k=0; k<lenCorse; k++){
            if(strcmp(corseSorted[i].partenza, corseSorted[k].partenza)<0){
                struct Corse temp = corseSorted[k];
                corseSorted[k] = corseSorted[i];
                corseSorted[i] = temp;
            }
        }
    }
    printData(corseSorted, lenCorse);
    free(corseSorted);
}

void sortByArrival(struct Corse *corse, int lenCorse){
    struct Corse *corseSorted = malloc(lenCorse*sizeof(lenCorse));

    for(int i=0; i<lenCorse; i++)
        corseSorted[i] = corse[i];

    for(int i=0; i<lenCorse; i++){
        for(int k=0; k<lenCorse; k++){
            if(strcmp(corseSorted[i].arrivo, corseSorted[k].arrivo)<0){
                struct Corse temp = corseSorted[k];
                corseSorted[k] = corseSorted[i];
                corseSorted[i] = temp;
            }
        }
    }
    printData(corseSorted, lenCorse);
    free(corseSorted);
}

void printData(struct Corse *corse, int lenCorse){
    fflush(stdout);
    for (int i = 0; i < lenCorse; i++) {
        printf("%s %s %s %02d/%02d/%02d %02d:%02d:%02d %02d:%02d:%02d %d\n", corse[i].codiceTratta, corse[i].partenza, corse[i].arrivo, corse[i].dd, corse[i].mm, corse[i].yyyy, corse[i].oraPartenza, corse[i].minPartenza, corse[i].secPartenza, corse[i].oraArrivo, corse[i].minArrivo, corse[i].secArrivo, corse[i].ritardo);
    }
}


