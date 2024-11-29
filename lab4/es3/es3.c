#include <stdio.h>
#include <stdlib.h>

int powerset_disp_rip(int pos, int *val, int *sol, int n, int count);
int checkCorrect(int *sol, int lenSol);

int main(void){
	FILE *infile = fopen("very_easy_test_set.txt", "r");
	int lenFile;
	int **vettVal, *vettSol, maxLenght=0;

	fscanf(infile, "%d\n", &lenFile);
	vettVal = malloc(lenFile*sizeof(int *));


	for(int i=0; i<lenFile; i++){
		vettVal[i] = malloc(4*sizeof(int));
		fscanf(infile, "%d %d %d %d\n", &vettVal[i][0], &vettVal[i][1], &vettVal[i][2], &vettVal[i][3]);
		if ((vettVal[i][0]+vettVal[i][1]+vettVal[i][2]+vettVal[i][3]) > maxLenght)
			maxLenght = vettVal[i][0]+vettVal[i][1]+vettVal[i][2]+vettVal[i][3];
	}

	vettSol = malloc(maxLenght*sizeof(int));


	for(int i=0; i<lenFile; i++)
		free(vettVal[i]);
	free(vettVal);
	free(vettSol);
	fclose(infile);
	return 0;
}

int powerset_disp_rip(int pos, int *val, int *sol, int n, int count) {
	int i;
	// stampa del vettore
	if (pos >= n) {
	printf("{ ");
	for (i=0; i<n; i++)
		if (sol[i]!=0)
			printf("%d ", val[i]);
	printf("} \n");
	return count+1;
	}
	
	// prendo un elemento e lo blocco
	sol[pos] = 0;
	count = powerset_disp_rip(pos+1, val, sol, n, count);
	// sblocco l'elemento che ho preso, prendendo l'elemento successivo
	sol[pos] = 1;
	count = powerset_disp_rip(pos+1, val, sol, n, count);
	// ritorno
	return count;
}


int checkCorrect(int *sol, int lenSol){
	int check = 1;
	for(int i=0; i<lenSol-1 && check == 1; i++){
		check = 0;
		if((sol[i] == 'z' && sol[i+1] == 'z') || (sol[i] == 'z' && sol[i+1] == 'r'))
			check = 1;
		if((sol[i] == 's' && sol[i+1] == 's') || (sol[i] == 's' && sol[i+1] == 't'))
			check = 1;
		if((sol[i] == 'r' && sol[i+1] == 's') || (sol[i] == 'r' && sol[i+1] == 't'))
			check = 1;
		if((sol[i] == 't' && sol[i+1] == 'z') || (sol[i] == 't' && sol[i+1] == 'r'))
			check = 1;
	}
	return check;
}
