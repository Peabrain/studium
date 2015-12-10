//Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

//es werden zwei Parameter an calculatorAdd bzw Sub übergeben, und es gibt einen Ausgabewert

// declaration der assemblervariablen und assemblerroutinen
extern double operator[16];
extern char operation[16];
extern double result;
extern void calculate();

void printHelp();
double calculateFormel(char *formel);

int main(int argc, char* argv[]) 
{
	int i,pos = 0;
	char formel[1024];
	formel[0] = 0;
	
	if(argc == 1)
	{
		printHelp();
		return 0;
	}
	else
	if(argc == 2 && strncmp(argv[1],"-d",2) == 0)
	{
		int j = 2,n = 10;
		char *plus = " + ";
		char *minus = " - ";
		double values[11] = {1.0,6.4,4.21,9.9,-4.6,12,96.2,-20.5,-63.111};
		time_t t;

    	time(&t);
	    srand((unsigned int)t);

		printf("Calculator Demo:\n");
		while(n)
		{
			formel[0] = 0;
			j = 2 + rand() % 5;
			for(i = 0;i < j;i++)
			{
				char v[256];
				sprintf(v,"%lf",values[rand() % 9]);
				strncpy(formel + strlen(formel),v,strlen(v) + 1);
				if(i < j-1)
				{
					if((rand() >> 3) & 1)
						strncpy(formel + strlen(formel),plus,strlen(plus) + 1);
					else
						strncpy(formel + strlen(formel),minus,strlen(minus) + 1);
				}
			}
			printf("Formel (%i): %s",n,formel);
			double res =calculateFormel(formel);
			printf(" = %lf\n",res);
			sleep(1);
			n--;
		}		
		return 0;
	}
	for(i = 1;i < argc;i++)
	{
		int l = strlen(argv[i]);
		strncpy(formel + pos,argv[i],l + 1);
		pos += l;
	}

	printf("%s = ",formel);
	double res =calculateFormel(formel);
	printf("%lf\n",res);

	return 0;
}
void printHelp()
{
	printf("Inkorrekte Eingabe.\n");
	printf("Bitte in der Form: <Befehl> Operator (+/-) Operator (+/-) Operator (+/-) Operator .....\n");
	printf("Zum Beispiel: <Befehl> 5 + 3.7 - 6\n");
	printf("Oder fuer eine Demo: <Befehl> -d\n");
}

double calculateFormel(char *formel)
{
	int i,pos = 0;
	int operator_num = 0;
	int op_num;
	char *lastOP = formel;
	op_num = 0;
	pos = strlen(formel);
	for(i = 0;i < pos;i++)
	{
		if(formel[i] == '+' || formel[i] == '-')
		{
			operation[op_num++] = formel[i];
			formel[i] = 0;
			sscanf(lastOP,"%lf",&operator[operator_num++]);
			lastOP = (formel + i + 1);
		}
	}
	sscanf(lastOP,"%lf",&operator[operator_num++]);
	calculate(op_num);
	return result;
}

