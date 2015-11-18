/**
 * File: trashcan.c
 * TI 2 - Betriebs- und Kommunikationssysteme
 * Freie Universitaet Berlin
 Andreas Timmermann, Nhu Quynh
 */
#include <stdio.h>
#include <stdlib.h>

/* benoetigte Struktur zum Erzeugen der Stack-Eintraege */
typedef struct item {
	int  value;
    void *next;
} item;

/* Zeiger auf oberstes Element */
item* head = NULL;

/* Freigabe eines Elements */
void trash(item* garbage){
	free(garbage);
}

/* Ein neues Element anlegen */
item* new_item(int value) {
	item *pItem = (item*)malloc(sizeof(item));
	pItem->next = NULL;
	pItem->value = value;
	return pItem;
}

/* is_empty testet , ob die Liste leer ist
   und liefert entsprechend 1 fuer leer, 0 fuer nicht leer */
int is_empty() {
    if(head != NULL) return 0;
	return 1;
}

/* das neue Element wird auf den Stack abgelegt */
void push(item *elem) {
	elem->next = head;
	head = elem;
	printf("push: %i\n",head->value);
}

/* entfernt das oberste Element vom Stack und gibt es zurŸck */
void *pop()
{
	item *pItem = NULL;
	if(is_empty()) return 0;
	pItem = head;
	head = pItem->next;
	pItem->next = NULL;
	printf("pop: %i\n",pItem->value);
	return pItem;
}

/* Teil b :
    nimmt zwei Operanden vom Stack, multipliziert diese und
    legt das Ergebnis auf dem Stack ab.
*/
int multiplication()
{
	printf("Initialisierung der Multiplikation vom Stack:\n");
	item *pOp1 = NULL,*pOp2 = NULL;
	pOp1 = pop();
	pOp2 = pop();
	if((pOp1 != NULL) && (pOp2 != NULL))
	{
		int iA = pOp1->value * pOp2->value;
		trash(pOp1);
		trash(pOp2);
		return iA;
	}
	printf("keine zwei Operanten auf dem Stack!\n");
	return 0;
}

int main()
{
    /*
     Testen!
     */

	int x;
	// erzeuge einige Items auf dem Stack
	for(x = 0;x < 10;x++)
	{
		item *pItem = new_item(x);
		push(pItem);
	}

	// multipliziere 3 Paare vom Stack
	for(x = 0;x < 3;x++)
	{
		int iE = multiplication();
		printf("Multiplikation der letzten beiden Zahlen auf dem Stack ist: %i\n",iE);
	}

	// hole die restlichen Items vom Stack und gib sie frei
	item *pItem = NULL;
	while((pItem = pop()) != NULL)
	{
		trash(pItem);
	}


}
