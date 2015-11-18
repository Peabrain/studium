//  Betriebs- und Kommunikationssysteme
//  Uebung 1
//	Aufgabe 2
//
//  Created by Andreas Timmermann on 17.10.15.
//	Matrikelnummer: 4994606
//	Gruppe 1

#include <stdio.h>

#define FLAG_DIV_BY_ZERO    0x01                                                                // define some defines for flags and arraysizes
#define FLAG_UNKNOWN_OP     0x02                                                                //                  -"-
#define LINE_LEN            256                                                                 //                  -"-

int main()
{
    FILE    *f = 0;                                                                             // define f as type FILE

    f = fopen("test.dat","r");                                                                  // open the file "test.data" and write the resultpointer in f
    if(f != NULL)                                                                               // compare f with NULL (check if the pointer f is valid)
    {                                                                                           // if f is valid then do ...
        int     iLinecounter = 0;                                                               // define iLinecounter as int and set it to 0 (the linecounter)
        char    pLine[LINE_LEN];                                                                // define pLine as char array with length of LINE_LEN (contains the line later)
        float   fSum = 0;                                                                       // define fSum as float and set it to 0 (contains the first operator of the comparisation)
        float   fCompSum = 0;                                                                   // define fCompSum as float and set it to 0 (contains the sum of the following operators)
        int     iParaCount = 0;                                                                 // define iParaCount as int and set it to 0 (the parametercount for sscanf)

        printf("test.dat loaded\n");

        while (fgets(pLine, LINE_LEN, f))                                                       // as long as a line is in file f, get a line from file f and put it in pLine
        {
            switch(iLinecounter)                                                                // switch between line 0 and all other lines
            {
                case 0:                                                                         // if line 0 then ...
                {
                    printf("---------------\n");                                                // some printings
                    printf("Erster Operant:\n");                                                //       -"-
                    printf("---------------\n");                                                //       -"-
                    iParaCount = sscanf(pLine,"%f",&fSum);                                      // get specific formated parameter from line 0 and set iParaCount the return of sscanf
                    if(iParaCount == 1)                                                         // if you get 1 correct float, then ...
                        printf("%f\n",fSum);                                                    // do some printings
                    else                                                                        // if not, then ..
                        printf("Error (line %i): missing first operator\n",iLinecounter);       // print an error

                    printf("----------------------\n");                                         // do some printings
                    printf("Nachfolgenden Operant:\n");                                         //        -"-
                    printf("----------------------\n");                                         //        -"_
                }break;																			// end case
                default:                                                                        // for all other lines do ...
                {
                    float   fS1,fS2,fS = 0;                                                     // define fS1, fS2, fS as float (fS1 and fS2 are operators for the sum, fS countains the partial sum)
                    char    cOp = 0;                                                            // define cOp as char. this will get the operation for the actual line
                    unsigned char   ucFlag = 0;                                                 // define ucFlag as unsigned char. will get the flags FLAG_... when an error occurs

                    iParaCount = sscanf(pLine,"%f%c%f",&fS1,&cOp,&fS2);                         // try to get the values for fS1, fS2 and cOp from the line. write the return from sscanf in iParaCount
                    if(iParaCount == 3)
                    {
                        switch(cOp)                                                             // switch between
                        {
                            case '+': fS = fS1 + fS2;break;                                     // if cOp == '+' then put fS1 + fS1 in fS
                            case '-': fS = fS1 - fS2;break;                                     // if cOp == '-' then put fS1 - fS1 in fS
                            case '*': fS = fS1 * fS2;break;                                     // if cOp == '*' then put fS1 * fS1 in fS
                            case '/':                                                           // if cOp == '/' then do ...
                            {
                                    if(fS2 == 0.0)                                              // check if the divisor is zero
                                            ucFlag = FLAG_DIV_BY_ZERO;                          // if yes, then set errorflag ucFlag
                                    else
                                            fS = fS1 / fS2;                                     // if not, then divide fS1 and fS2 and put the result in fS
                            }break;																// end case
                            default: ucFlag = FLAG_UNKNOWN_OP;break;                            // if any other value in cOp then set errorflag ucFlag
                        }
                        if(!ucFlag)																// if no errorflag is set in ucFlag then ...
                        {
                            fCompSum += fS;                                                     // add fSum to the sum of the following operators (fCompSum)
                            printf("%f%c%f=%f\n",fS1,cOp,fS2,fS);                               // some rintings
                        }
                        else																	// if errorflag is set then
                        if(ucFlag & FLAG_DIV_BY_ZERO)                                           // if division by zero is set in ucFlag then
                            printf("Error (line %i): division by zero\n",iLinecounter);         // print an error
                        else
                        if(ucFlag & FLAG_UNKNOWN_OP)                                            // if unknown oeration is set in ucFlaf then
                            printf("Error (line %i): unknown operation\n",iLinecounter);        // print an error
                    }
                }break;																			// end case
            }
            iLinecounter++;                                                                     // increase the linecounter (iLinecounter)
        }
        printf("----------------------------------------------------------------------\n");     // some printings
        printf("Vergleich des ersten Operaten mit der Summe aller folgenden Operanten:\n");     //      -"-
        printf("----------------------------------------------------------------------\n");     //      -"-
        if(fSum == fCompSum)                                                                    // if the first operator (fSum) and the sum of the following operators (fCompSum) are the same, then ..
            printf("%f == %f\n",fSum,fCompSum);                                                 // print that they are equal
        else
            printf("%f != %f\n",fSum,fCompSum);                                                 // if not then print they are not equal
        printf("----------------------------------------------------------------------\n");
        fclose(f);                                                                              // close the file f;
    }
    else																						// if file cannot be open then ...
        printf("cannot open file\n");                                                           // some printings
    return 0;
}
