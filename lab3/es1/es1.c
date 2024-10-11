#include <stdio.h>

int maggioritario(int vett[], int lenVett);
int maggioritarioUnwrapped(int vett[], int l, int r);

int main(void){
	int vett[11] = {1, 1, 1, 4, 1, 6, 1, 8, 3, 10, 2};
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
	if(intL ==  intR){
		return intL;
	}else if(intL == -1 && intR != -1){
		return intR;
	}else if(intL != -1 && intR == -1){
		return intL;
	}else{
		return -1;
	}
}
