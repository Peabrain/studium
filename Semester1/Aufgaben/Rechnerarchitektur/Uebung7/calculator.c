//Fabien Geeraert und Ailis Oßwald, Tutorium 02 bei Christoph Van Heteren-Frese
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//es werden zwei Parameter an calculatorAdd bzw Sub übergeben, und es gibt einen Ausgabewert

// declaration der assemblervariablen und assemblerroutinen
extern double operator[16];
extern char operation[16];
extern double result;
extern void calculate();

int main(int argc, char* argv[]) 
{
	int i,pos = 0;
	char formel[1024];
	formel[0] = 0;
	int operator_num = 0;
	int op_num;
	
	for(i = 1;i < argc;i++)
	{
		int l = strlen(argv[i]);
		strncpy(formel + pos,argv[i],l + 1);
		pos += l;
	}

	char *lastOP = formel;
	op_num = 0;
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
	
	
	for(i = 0;i < op_num;i++)
	{
		printf("%lf %c ",operator[i],operation[i]);
	}
	printf("%lf",operator[i]);
	calculate(op_num);
	printf(" = %lf\n",result);

	return EXIT_SUCCESS;
}
