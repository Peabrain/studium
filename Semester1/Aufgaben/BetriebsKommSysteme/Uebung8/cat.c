#include <stdio.h>
#include <stdlib.h>

#define LINE_LEN            16384
int main(int argv, char **argc)
{
	if(argv == 2)
	{
		FILE *f = fopen(argc[1],"r");
		if(f != NULL)
		{
			char    pLine[LINE_LEN];
			while (fgets(pLine, LINE_LEN, f))
			{
				fprintf(stdout,"%s",pLine);
			}
			fclose(f);
			printf("\n");
		}
	}
	return 0;
}
