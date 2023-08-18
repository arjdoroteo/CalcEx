#include <stdio.h>
#include "dHb.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

char* decimal2hex( char* inputA )
{
    int val = atoi(inputA);
    
    char * result = malloc(sizeof(char)*100);
    int i = 1, j, temp, k = 0;
    char hexa_Number[100];

    char hexa_OrderedNumber[100];
    while ( val !=0 )
    {
        temp = val % 16;

        if ( temp < 10 )
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

    for ( j = i - 1; j > 0; j-- )
    {
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

    while ( val != 0 )
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
    char * result = malloc(sizeof(char)*100);
    int i = 0;
    while (inputA[i]) {
 
        switch (inputA[i]) {
        case '0':
            strcat( result, "0000" );
            break;
        case '1':
            strcat( result, "0001" );
            break;
        case '2':
            strcat( result, "0010" );
            break;
        case '3':
            strcat( result, "0011" );
            break;
        case '4':
            strcat( result, "0100" );
            break;
        case '5':
            strcat( result, "0101" );
            break;
        case '6':
            strcat( result, "0110" );
            break;
        case '7':
            strcat( result, "0111" );
            break;
        case '8':
            strcat( result, "1000" );
            break;
        case '9':
            strcat( result, "1001" );
            break;
        case 'A':
        case 'a':
            strcat( result, "1010" );
            break;
        case 'B':
        case 'b':
            strcat( result, "1011") ;
            break;
        case 'C':
        case 'c':
            strcat( result, "1100" );
            break;
        case 'D':
        case 'd':
            strcat( result, "1101" );
            break;
        case 'E':
        case 'e':
            strcat( result, "1110") ;
            break;
        case 'F':
        case 'f':
            strcat( result, "1111" );
            break;
        case '.':
            printf(".");
        default:
            printf("\nInvalid hexadecimal digit %c",
                   inputA[i]);
        }
        i++;
    }
    return result;
};

char* hex2decimal( char* inputA )
{
    int decimalnumber, i;
    char * result = malloc(sizeof(char)*100);
    int cnt;

    int digit;
  
    cnt = 0;
    decimalnumber = 0;
    
    for (i = ( strlen(inputA) - 1 ); i >= 0; i-- ) {
        
        switch (inputA[i]) {
        case 'A':
            digit = 10;
            break;
        case 'B':
            digit = 11;
            break;
        case 'C':
            digit = 12;
            break;
        case 'D':
            digit = 13;
            break;
        case 'E':
            digit = 14;
            break;
        case 'F':
            digit = 15;
            break;
        default:
            digit = inputA[i] - 0x30;
        }

        decimalnumber = decimalnumber + (digit) * pow((double)16, (double)cnt);
        cnt++;
    }
    sprintf(result, "%d", decimalnumber);
    return result;
};

char* bin2decimal( char* inputA )
{
    char * result = malloc(sizeof(char)*100);
    long long int n = atoi(inputA);

    int dec = 0, i = 0, rem;

    while ( n != 0 ) 
    {
        rem = n % 10;
        n /= 10;

        dec += rem * pow( 2, i );
        ++i;
    }

    
    sprintf(result, "%ld", dec);
    return result;
};

char* bin2hex( char* inputA )
{
    char * result = malloc(sizeof(char)*100);

    long binaryval = atoi(inputA);
    long int hexadecimalval = 0, i = 1, remainder;
    while (binaryval != 0)
    {
        remainder = binaryval % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        binaryval = binaryval / 10;
    }
    sprintf(result, "%lX", hexadecimalval);
    return result;
};


t_converterOpsData data2 =
{
    .inputA = 0,
    .converterOps = INVALID_converterOps,
    .result = 0,
};

char Converterresult[50];

const char* converterCase(){

    char converterOps = 'A'; 
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