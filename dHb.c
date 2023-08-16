#include <stdio.h>
#include "dHb.h"
#include <string.h>
#include <stdlib.h>

char* decimal2hex( char* inputA )
{
    int val = atoi(inputA);
    
    int i = 1, j, temp;
    char hexa_Number[100];

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
            hexa_Number[i++] = temp;
            val = val / 16;
        }
    }
    
    
    return hexa_Number;
};

char* decimal2bin( char* inputA )
{
    return "Hello World";
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
        // printf("%s\n\n", data2.inputA);
        data2.result = converterOpsHandlerList[data2.converterOps]( data2.inputA );
        printf("Operation: %s, Result: %s\n", converterOpsTitle[data2.converterOps], data2.result);
        scanf("%c", &converterOps);
    }

    sprintf(Converterresult, "%s: %s", converterOpsTitle[data2.converterOps], data2.result);
    
    return Converterresult;
}