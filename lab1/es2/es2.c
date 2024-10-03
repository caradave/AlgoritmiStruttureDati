#include <stdlib.h>
#include <stdio.h>
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

void selezionaDati(struct Corse *corse, int lenCorse);

int main(void){
    FILE *infile = fopen("/home/davide/Scrivania/polito/apa/AlgortimiStruttureDati/lab1/es2/corse.txt", "r");
    int fileLen;

    if(infile == NULL){
        printf("errore nell'apetura del file\n");
        return -1;
    }

    fscanf(infile, "%d", &fileLen);

    struct Corse *corse = malloc(fileLen*sizeof(struct Corse));

    for(int i=0; i<fileLen; i++){
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

    selezionaDati(corse,fileLen);

    free(corse);
    fclose(infile);
    return 0;
}

void selezionaDati(struct Corse *corse, int lenCorse){
    int selezione;
    char stazioneDesiderata[30];
    int startDD, startMM, startYYYY, finishDD, finishMM, finishYYYY;
    int ritardoTot;
    printf("1 se si desidera selezionare una stazione di partenza\n2 se si desidera selezionare la stazione di arrivo\n3 se si desidera selezionare tutte le corse che sono partite in un intevallo di date\n4 se si desidera selezionare tutte le corse partite tra due date che hanno fatto ritardo\n5 se si desidera elencare il ritardo complessivo di una tratta\nScelta: ");
    scanf("%d", &selezione);

    switch (selezione)
    {
    case 1:
		printf("inserire la stazione desiderata: ");
		scanf("%s", stazioneDesiderata);
        for(int i=0; i<lenCorse; i++){
            if(strcmp(stazioneDesiderata, corse[i].partenza) == 0)
                printf("%s %s %s %d/%d/%d %d:%d:%d %d:%d:%d %d\n", corse[i].codiceTratta, corse[i].partenza, corse[i].arrivo, corse[i].dd, corse[i].mm, corse[i].yyyy, corse[i].oraPartenza, corse[i].minPartenza, corse[i].secPartenza, corse[i].oraArrivo, corse[i].minArrivo, corse[i].secArrivo, corse[i].ritardo);
        }        break;
    case 2:
        printf("inserire la stazione desiderata: ");
        scanf("%s", stazioneDesiderata);
        for(int i=0; i<lenCorse; i++){
            if(strcmp(stazioneDesiderata, corse[i].arrivo) == 0)
                printf("%s %s %s %d/%d/%d %d:%d:%d %d:%d:%d %d\n", corse[i].codiceTratta, corse[i].partenza, corse[i].arrivo, corse[i].dd, corse[i].mm, corse[i].yyyy, corse[i].oraPartenza, corse[i].minPartenza, corse[i].secPartenza, corse[i].oraArrivo, corse[i].minArrivo, corse[i].secArrivo, corse[i].ritardo);
        }
        break;
    case 3:
        printf("inserire al data da cui si desidera iniziare la selezione (formato DD/MM/YYYY): ");
        scanf("%d/%d/%d", &startDD, &startMM, &startYYYY);
        printf("inserire la data con la quale si desidera interromepere la scansione (formato DD/MM/YYYY): ");
        scanf("%d/%d/%d", &finishDD, &finishMM, &finishYYYY);
		//printf("%d/%d/%d %d/%d/%d\n", startDD, startMM, startYYYY, finishDD, finishMM, finishYYYY);
        for(int i=0; i<lenCorse; i++){
            if(startYYYY <= corse[i].yyyy && corse[i].yyyy <= finishYYYY)
                if(startMM <= corse[i].mm && corse[i].mm <= finishMM)
                    if(startDD <= corse[i].dd && corse[i].dd <= finishDD)
                    	printf("%s %s %s %d/%d/%d %d:%d:%d %d:%d:%d %d\n", corse[i].codiceTratta, corse[i].partenza, corse[i].arrivo, corse[i].dd, corse[i].mm, corse[i].yyyy, corse[i].oraPartenza, corse[i].minPartenza, corse[i].secPartenza, corse[i].oraArrivo, corse[i].minArrivo, corse[i].secArrivo, corse[i].ritardo);
		 }
	   break;
		case 4:
	   		printf("inserire al data da cui si desidera iniziare la selezione (formato DD/MM/YYYY): ");
            scanf("%d/%d/%d", &startDD, &startMM, &startYYYY);
            printf("inserire la data con la quale si desidera interromepere la scansione (formato DD/MM/YYYY): ");
            scanf("%d/%d/%d", &finishDD, &finishMM, &finishYYYY);
            for(int i=0; i<lenCorse; i++){
                if(startYYYY <= corse[i].yyyy && corse[i].yyyy <= finishYYYY)
                    if(startMM <= corse[i].mm && corse[i].mm <= finishMM)
                        if(startDD <= corse[i].dd && corse[i].dd <= finishDD)
                            if(corse[i].ritardo != 0)
                                printf("%s %s %s %d/%d/%d %d:%d:%d %d:%d:%d %d\n", corse[i].codiceTratta, corse[i].partenza, corse[i].arrivo, corse[i].dd, corse[i].mm, corse[i].yyyy, corse[i].oraPartenza, corse[i].minPartenza, corse[i].secPartenza, corse[i].oraArrivo, corse[i].minArrivo, corse[i].secArrivo, corse[i].ritardo);
            }
	   	break;
		case 5:
	   		printf("inserire al data da cui si desidera iniziare la selezione (formato DD/MM/YYYY): ");
            scanf("%d/%d/%d", &startDD, &startMM, &startYYYY);
            printf("inserire la data con la quale si desidera interromepere la scansione (formato DD/MM/YYYY): ");
            scanf("%d/%d/%d", &finishDD, &finishMM, &finishYYYY);
            for(int i=0; i<lenCorse; i++){
                if(startYYYY <= corse[i].yyyy && corse[i].yyyy <= finishYYYY)
                    if(startMM <= corse[i].mm && corse[i].mm <= finishMM)
                        if(startDD <= corse[i].dd && corse[i].dd <= finishDD)
                            if(corse[i].ritardo != 0)
                                ritardoTot += corse[i].ritardo;
            }
		break;
    default:
        printf("non è stato inserito un valore valido");
        break;
    
    }
}
