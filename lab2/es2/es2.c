#include <stdio.h>
#include <stdlib.h>

int **malloc2dR(int row, int col);
int **readData(FILE *infile);
void separa(int **mat, int white[], int black[], int row, int col);

int main(void){
    FILE *infile = fopen("mat.txt", "r");
    int **mat;
    
    if (infile == NULL){
        printf("impossibile aprire il file");
        return -1;
    }

    readData(infile);
    
    

    fclose(infile);
    return 0;
}


int **malloc2dR( int row, int col){
    int **mat = (int **)malloc(col*sizeof(int*));
    for(int i=0; i<row; i++){
        mat[i] = (int *)malloc(col*sizeof(int));
    }
    return mat;
}


int **readData(FILE *infile){
    int col, row;
    fscanf(infile, "%d %d\n", &col, &row);

    int **mat = malloc2dR(row, col);

    for(int i=0; i<row; i++){
        for(int k=0; k<col; k++){
            fscanf(infile, "%d", &mat[i][k]); 
        }
    }
    
    int len = col*row;
    int white[(len/2)+1], black[len/2];
    separa(mat, white, black, row, col);
    
    // printf("%d", len);

    if(len%2 == 0){
        for(int i=0; i<(row*col)/2; i++){
            printf("bianchi: %d, neri: %d", white[i], black[i]);
        }
    }else{
        for(int i=0; i<(row*col)/2; i++){
            printf("bianchi: %d, neri: %d\n", white[i], black[i]);
        }
        printf("bianchi: %d, neri: -\n", white[(len/2)]);
    }
    return mat;
}

void separa(int **mat, int white[], int black[], int row, int col){
    int choose = 0, nWhite=0, nBlack=0;
    for(int i=0; i<row; i++){
        for(int k=0; k<col; k++){
            if(choose == 0){
                white[nWhite] = mat[i][k];
                choose = 1;
                nWhite++;
            }else{
                black[nBlack] = mat[i][k];
                nBlack++;
                choose = 0;
            }
        }
    }
}
