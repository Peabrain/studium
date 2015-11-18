// Rechnerarchitektur
// Übung 4
//
// Andreas Timmermann, Shima Shahadifar
// MtrNr: 4994606, 5018598
// Gruppe 2

#include <stdio.h>
#include <time.h>

long int collatz(long int);								// Deklaration der Assemblerfunktion

long int collatz_c(long int k)					// Fibonacci C Funktion
{
	printf("collatz in c\n");
	printf("============\n");
	long int i = 0;
	while(k > 1)
	{
		i++;
		printf("%lu,",k);
		if(!(k & 1))
		{
			k >>= 1;
		}
		else
		{
			k = k * 3 + 1;
		}
	}
	printf("%lu\n",k);
	return i;
}
int	main()
{
	long int n = 0,a_c,a;

	printf("Collatz Conjecture:\n Bitte geben Sie 'n' ein: ");
	if(scanf("%ld",&n) == 1)
	{
		a = collatz(n);
		a_c = collatz_c(n);
		printf("Rueckgabe der einzelnen Funktionen: (asm) %lu, (c) %lu\n",a,a_c);
	}

	return 0;
}

