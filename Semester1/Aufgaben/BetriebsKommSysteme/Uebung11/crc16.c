#include <stdio.h>
#include <stdlib.h>

void printSeq(char *seq,int iSeqLen);
void encSeq(char *seq,int iSeqLen,char *seqEnc,int iCodeLen,int iCode);

int main(int argv, char **argc)
{
	unsigned int iCode = 0b11000000000000101;
	int iCodeLen = 17;
	char pcSequence[] = {0b10101100,0b10101100,0b00001101,0b00001101,0,0}; 
	char pcSequenceCoded[] = {0,0}; 

	printSeq(pcSequence,48);
	printf("\n");
	encSeq(pcSequence,48,pcSequenceCoded,iCodeLen,iCode);
	printSeq(pcSequence,48);
	printf("\n");
}
void printSeq(char *seq,int iSeqLen)
{
	int i;
	for(i = 0;i < iSeqLen;i++)
	{
		if(seq[i/8] & (1 << (i & 7)))
			printf("1");
		else
			printf("0");
	}
}
void encSeq(char *seq,int iSeqLen,char *seqEnc,int iCodeLen,int iCode)
{
	int i,j;
	char *mem = (char*)malloc(iSeqLen / 8 + 1);
	memcpy(mem,seq,iSeqLen / 8 + 1);
	for(i = 0;i < iSeqLen - 1;i++)
	{
		if(mem[i/8] & (1 << (i & 7)))
		{
			seqEnc[i / 8] |= 1 << (i & 7);
			for(j = 0;j < iCodeLen;j++)
			{
				mem[(i+j) / 8] ^= (((iCode >> j) & 1) << ((i+j) & 7));
			}
		}
	}
	printSeq(seqEnc,iSeqLen);
	printf("\n");
	seq[iSeqLen / 8 - 1] |= (seqEnc[iSeqLen / 8 - 1]);
	seq[iSeqLen / 8 - 2] |= (seqEnc[iSeqLen / 8 - 2]);
	free(mem);
}
