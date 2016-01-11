#include <stdio.h>
#include <stdlib.h>

extern unsigned int fib1(unsigned int);

int eingabeZahl() {
	int eingabe;
	printf("\nEingabe Zahl: ");
	scanf("%f", &eingabe);
	return eingabe;
}

int main(){
	int x1=1;
	int x2=0;
	int k=0;
	int n=eingabeZahl();
	int i;
	for (i=n; i>0; i--){
		k=x1+x2;
		x1=x2;
		x2=k;
	}
	return x1;
}


