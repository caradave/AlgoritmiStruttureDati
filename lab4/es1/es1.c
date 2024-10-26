#include <stdio.h>
#include <stdlib.h>

int **allocaArchi(int **archi, int lenFile);
void freeArchi(int **archi, int lenFile);
void powerset_div_conq(int pos, int *val, int *sol, int n, int start, int **check);
int checkVal(int *sol, int **check, int vertici, int lenSubset);

int main(void){
	FILE *infile = fopen("grafo.txt", "r");
	int numVertici, lenFile;
	int **archi;
	int *vertici, *sol;

	fscanf(infile, "%d %d\n", &numVertici, &lenFile);
	
	archi = allocaArchi(archi, lenFile);
	vertici = malloc(numVertici * sizeof(int));
	sol = malloc(numVertici * sizeof(int));
	for(int i=0; i<numVertici; i++)
		vertici[i] = i;

	for(int i=0; i<lenFile; i++){
		fscanf(infile, "%d %d\n", &archi[i][0], &archi[i][1]);
		//printf("%d %d\n", archi[i][0], archi[i][1]);
	}
	powerset_div_conq(0, vertici, sol, numVertici, 0, archi);	
	
	freeArchi(archi, lenFile);
	free(vertici);
	fclose(infile);
	return 0;
}

int **allocaArchi(int **archi, int lenFile){
	archi = malloc(lenFile*sizeof(int *));
	
	for(int i=0; i<lenFile; i++)
		archi[i] = malloc(2*sizeof(int));

	return archi;
}

void freeArchi(int **archi, int lenFile){
	for(int i=0; i<lenFile; i++)
		free(archi[i]);
	
	free(archi);
}

void powerset_div_conq(int pos, int *val, int *sol, int n, int start, int **check) {
	int i;
	if (start >= n) {
		if(checkVal(sol, check, n, pos)){
			printf("{ ");
			for (i = 0; i < pos; i++)
				printf("%d ", sol[i]);
			printf("} \n");
		}
		return;
	}
	for (i = start; i < n; i++) {
		sol[pos] = val[i];
		powerset_div_conq(pos+1, val, sol, n, i+1, check);
	}
	powerset_div_conq(pos, val, sol, n, n, check);
	return;
}

int checkVal(int *sol, int **check, int vertici, int lenSubset){
	int bool=0;
	for(int i=0; i<vertici; i++){
		bool = 0;
		for(int j=0; j<lenSubset; j++)
			if(sol[j] == check[i][0] || sol[j] == check[i][1])
				bool = 1;
		if (bool == 0)
			return 0;
		
	}


	return 1;
}
