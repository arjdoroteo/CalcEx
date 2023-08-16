#include <stdio.h>
#include "dHb.h"
#include <string.h>
#include <stdlib.h>

char* decimal2hex( char* inputA )
{
    int val = atoi(inputA);
    
    char * result = malloc(sizeof(char)*100);
    int i = 1, j, temp, k = 0;
    char hexa_Number[100];

    char hexa_OrderedNumber[100];
    while (val !=0)
    {
        temp = val % 16;

        if (temp < 10)
        {
            temp = temp + 48;
        }
        else
        {
            temp = temp + 55;
        }
        hexa_Number[i++] = temp;
        val = val / 16;
    }

    for (j = i - 1; j > 0; j--)
    {
        // printf("%c", hexa_Number[j]);
        hexa_OrderedNumber[k] = hexa_Number[j];
        k++;
    }

    hexa_OrderedNumber[k] = '\0';
    strcpy(result,hexa_OrderedNumber);
    return result;
};

char* decimal2bin( char* inputA )
{
    long long bin = 0;
    int val = atoi(inputA);
    int rem, i = 1;
    char * result = malloc(sizeof(char)*100);

    while (val != 0)
    {
        rem = val % 2;
        val /= 2;

        bin += rem *i;

        i *= 10;
    }

    sprintf(result, "%ld", bin);

    return result;
};

char* hex2bin( char* inputA )
{
    return "Hello World";
};

char* hex2decimal( char* inputA )
{
    return "Hello World";
};

char* bin2decimal( char* inputA )
{
    return "Hello World";
};

char* bin2hex( char* inputA )
{
    return "Hello World";
};


t_converterOpsData data2 =
{
    .inputA = 0,
    .converterOps = INVALID_converterOps,
    .result = 0,
};

char Converterresult[50];

const char* converterCase(){

    char converterOps = 'A'; // where did A come from?
    printf("Conversion: ");
    scanf( " %c", &converterOps );

    switch( converterOps )
    {
        case 'H':
        {
            data2.converterOps = DECIMAL2HEX;
        }
        break;
        case 'B':
        {
            data2.converterOps = DECIMAL2BIN;
        }
        break;
        case 'I':
        {
            data2.converterOps = HEX2BIN;
        }
        break;
        case 'D':
        {
            data2.converterOps = HEX2DECIMAL;
        }
        break;
        case 'E':
        {
            data2.converterOps = BIN2DECIMAL;
        }
        break;
        case 'N':
        {
            data2.converterOps = BIN2HEX;
        }
        break;
        default:
        {
            data2.converterOps = INVALID_converterOps;
        }
        break;
        }

    if( INVALID_converterOps > data2.converterOps )
    {
        char * temp [255];
        printf("Input A: ");
        scanf( "%s", &temp );

        data2.inputA = temp;
        data2.result = converterOpsHandlerList[data2.converterOps]( data2.inputA );
        printf("Operation: %s, Result: %s\n", converterOpsTitle[data2.converterOps], data2.result);

        scanf("%c", &converterOps);
    }

    sprintf(Converterresult, "%s: %s", converterOpsTitle[data2.converterOps], data2.result);
    
    return Converterresult;
}