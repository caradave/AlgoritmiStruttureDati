#include <stdio.h>

int gcd(int a, int b);

int main(void){
	printf("%d\n", gcd(1358, 1732));
	return 0;
}

int gcd(int a, int b){
	if (a == b){
		return a;
	}
	if (a < b){
		int temp = a;
		a = b;
		b = temp;
	}


	if (a%2 == 0 && b%2 == 0){
		return 2 * gcd(a/2, b/2);
	}else if(a%2 != 0 && b%2 == 0){
		return gcd(a, (b/2));
	}else if(a%2 == 0 && b%2 != 0){
		return gcd((a/2), b);
	}else if(a%2 != 0 && b%2 != 0){
		return gcd((a-b)/2, b);
	}

}
