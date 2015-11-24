#include <stdio.h>
#include <stdlib.h>

/*Implementierung einer Prozessverwaltung:

Implementieren Sie die durch das Framework vorgegebene Prozessverwaltung,
die eine Menge von Prozessen aus der Datei prcs.dat auslesen,und diese
in eine doppelt verkettete Liste einfuegen soll.

Nun soll Prozess um Prozess der Reihenfolge ihrer ids entsprechend
aus der Liste entfernt werden,wobei die uebrig gebliebenen Prozesse in jeder
Iteration ausgegeben werden.

Die Prozesse sind in der Datei prcs.dat Zeile fuer Zeile in der Form:
    ProzessId,Ankunftszeit,Ausfuehrungszeit
gespeichert.

*/

struct pData //Daten der doppelt verketteten Liste
{
 int pId;//ProzessID
 int aTime;//Ankunftszeit
 int sTime;//Ausfuehrungszeit

 struct pData *next;
 struct pData *prev;
  /*Struktur vervollstaendigen */
};

//Um Tipparbeit zu sparen
typedef struct pData PROCESS;
typedef PROCESS *LINK;

LINK findNextProcess(LINK head);

void addProcess(LINK head,LINK neu);
void deleteProcess(LINK current);

void printPr(LINK current);//Methode zur Ausgabe eines Prozesses

void printList(LINK head);//Alle Prozesse der Liste ausgeben

void readProcesses(LINK head);//Einlesen der Prozesse

int main(void)
{
 LINK next = 0;
 LINK head = 0;

/*TODO:head initialisieren*/
	head = (LINK)malloc(sizeof(PROCESS));
	head->pId = 0;
	head->next = head;
	head->prev = head;

 readProcesses(head);

  while(head->next!=head)
 {
   printList(head);
   next=findNextProcess(head);
   deleteProcess(next);
 }

return 0;
}

/*==========================================================================
Implementierung der Methoden*/


//Liest die Prozesse ein und erstellt die Liste
void readProcesses(LINK head)
{
 /*TODO:implementieren*/
 char linebuffer[256];
 int i = 0;
 FILE *f = fopen("prcs.dat","r");
 if(f != 0)
 {
 	while(fgets(linebuffer,256,f))
	{
		int a,b,c;
		if(sscanf(linebuffer,"%i,%i,%i",&a,&b,&c) == 3)
		{
			LINK h = (LINK)malloc(sizeof(PROCESS));
			h->pId = a;
			h->aTime = b;
			h->sTime = c;
			addProcess(head,h);
		}
	}
 	fclose(f);
 }

}


//Einen Prozess an das Ende der Liste (also vor head) einfuegen
void addProcess(LINK head,LINK neu)
{
 /*TODO:implementieren*/
	LINK prev = head->prev;
	neu->next = head;
	prev->next = neu;
	neu->prev = prev;
	head->prev = neu;
	printf("add process: %i,%i,%i\n",neu->pId,neu->aTime,neu->sTime);
}

//Loeschen des angegebenen Knotens
void deleteProcess(LINK current)
{
 /*TODO:implementieren*/
	LINK prev = current->prev;
	LINK next = current->next;

	prev->next = next;
	next->prev = prev;
	free(current);
}


/*gibt den Prozess mit der kleinsten Id aus der Liste zurueck*/

LINK findNextProcess(LINK head)
{
 /*TODO:implementieren*/
 return head->next;
}


/*Ausgabemethoden fuer die Prozesse und die gesamte Liste*/
void printPr(LINK current)
{
 printf("\n pId:%d arrival time:%d service time:%d\n ",current->pId,current->aTime,current->sTime);
}

void printList(LINK head)
{
     printf("\n\n Current QUEUE of PROCESSES ---------------------------------------\n\n");
     LINK curr=head->next;
     while(curr!=head)
     {
      printPr(curr);
      curr=curr->next;
     }
}


