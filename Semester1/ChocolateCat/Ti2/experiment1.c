#include <stdio.h>

int ist_zahl_gerade(int);								// rückgabewerd 0 ist gerade und 1 ist ungerade

int main()												// Main-Funktion
{
	int	iZahl = 0;										// Definiere die Variable iZahl als int und schreibe die 21 in iZahl
	int iIstGerade = 0;									// Definiere die Variable iIstGerade als int und schreibe die 0 in iIstGerade

	printf("Gib eine Zahl ein: ");						// Aufforderung zur Zahleneingabe
	scanf("%d",&iZahl);									// Nimm die Zahl und schreib sie in iZahl. ('&' niemals vergessen!!!!)
	iIstGerade = ist_zahl_gerade(iZahl);				// Springe zur Assembler-Funktion und schreibe den Rückgabewert in iIstGerade
	if(iIstGerade == 0)									// Wenn iIstGerade gleich 0 dann ...
	{
		printf("Die Zahl %d ist gerade.\n",iZahl);		// Gib diesen Text aus
	}
	else												// ansonsten
	if(iIstGerade == 1)									// Wenn iIstGerade gleich 1 dann ...
	{
		printf("Die Zahl %d ist ungerade.\n",iZahl);	// Gib diesen Text aus
	}
	return 0;											// beenden des Programms mit Fehlercode 0
}

