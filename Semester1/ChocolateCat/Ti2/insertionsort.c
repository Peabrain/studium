//Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>

#define LEN 10

extern void insertionsort(char*, char);

void printString(char* to_show, char len) {
	char i;
	for(i=0; i<len; i++) {
		if(i == (len-1)) { // letztes Element
			printf("%c\n", to_show[i]);
		} else {
			printf("%c, ", to_show[i]);
		}
	}
}

int main(int argc, char* argv[]){
	int i;
	srand(time(NULL));	
	char to_sort[LEN];
	for(i=0; i<LEN; i++) {
		to_sort[i] = rand() % ('Z'-'A')+'A';
	}

	printString(to_sort, LEN);
	insertionsort(to_sort, LEN);
	printString(to_sort, LEN);
	
	return EXIT_SUCCESS;
}
