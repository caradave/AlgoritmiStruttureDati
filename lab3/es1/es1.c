#include <stdio.h>

int maggioritario(int vett[], int lenVett);
int maggioritarioUnwrapped(int vett[], int l, int r);
int checkMaggioritario(int vett[], int maybeMaggR, int maybeMaggL, int l, int r);

int main(void){
	int vett[11] = {1, 7, 1, 4, 1, 6, 1, 8, 1, 10, 1};
	maggioritario(vett, 11);
}

int maggioritario(int vett[], int lenVett){
	printf("%d\n", maggioritarioUnwrapped(vett, 0, lenVett-1));
	return -1;
}

int maggioritarioUnwrapped(int vett[], int l, int r){
	if(l>=r){
		return vett[l];
	}
	int m = (l+r)/2;
	int intL, intR;
	intL = maggioritarioUnwrapped(vett, l, m);
	intR = maggioritarioUnwrapped(vett, m+1, r);
	return checkMaggioritario(vett, intL, intR, l, r);
}

int checkMaggioritario(int vett[], int maybeMaggR, int maybeMaggL, int l, int r){
	int ricorrenzeR=0, ricorrenzeL=0;
	printf("maybeMaggR: %d, maybeMaggL: %d, left-end: %d, right-end: %d\n", maybeMaggL, maybeMaggR, l, r);
	if(maybeMaggL == maybeMaggR)
		return maybeMaggR;

	for(int i=l; i<r+1; i++){
		if(vett[i] == maybeMaggR)
			ricorrenzeR++;
		if(vett[i] == maybeMaggL)
			ricorrenzeL++;
		printf("ciclio: vett[i] %d, ricorrenzeR: %d, ricorrenzeL: %d\n", vett[i], ricorrenzeR, ricorrenzeL);
	}
	if(ricorrenzeR > (r+1-l)/2){
		printf("MaggR: %d, soglia: %d\n", maybeMaggR, (r-l)/2);	
		return maybeMaggR;
	}
	if(ricorrenzeL > (r+1-l)/2){
		printf("MaggL: %d, soglia: %d\n", maybeMaggL,  (r-l)/2);
		return maybeMaggL;
	}
	return -1;	
}
