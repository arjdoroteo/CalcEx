#include "bitwise.h"
#include <stdio.h>
int shiftRight( int inputA, int inputB )
{
   
    return ( inputA >> inputB );
}

int shiftLeft( int inputA, int inputB )
{
    return ( inputA << inputB );
}

int andnum( int inputA, int inputB )
{
    return ( inputA & inputB );
}

int ornum( int inputA, int inputB )
{
    return ( inputA | inputB );
}

int xornum( int inputA, int inputB )
{
    return ( inputA ^ inputB );
}

int notnum( int inputA, int inputB )
{
    return ( ~inputA );;
}

t_bitOpsData data4 =
{
    .inputA = 0,
    .inputB = 0,
    .bitOps = INVALID_bitOps,
    .result = 0,
};

char Bitwiseresult[50];

const char* bitwiseCase(){

    char bitOps = 'A'; // where did A come from?
    printf("Bitwise Operand(NOT will ignore second input): ");
    scanf( " %c", &bitOps );

    switch( bitOps )
    {
        case 'R':
        {
            data4.bitOps = SHIFTRIGHT;
        }
        break;
        case 'L':
        {
            data4.bitOps = SHIFTLEFT;
        }
        break;
        case '&':
        {
            data4.bitOps = ANDNUM;
        }
        break;
        case '|':
        {
            data4.bitOps = ORNUM;
        }
        break;
        case '^':
        {
            data4.bitOps = XORNUM;
        }
        break;
        case '~':
        {
            data4.bitOps = NOTNUM;
        }
        break;
        default:
        {
            data4.bitOps = INVALID_bitOps;
        }
        break;
    }

    if( INVALID_bitOps > data4.bitOps )
    {
        printf("Input A: ");
        scanf( "%i", &data4.inputA );
        printf("Input B: ");
        scanf( "%i", &data4.inputB );
        data4.result = bitOpsHandlerList[data4.bitOps]( data4.inputA, data4.inputB );
        printf("Operation: %s, Result: %i\n\n\n", bitOpsTitle[data4.bitOps], data4.result);
        scanf("%c", &bitOps);
    }

    sprintf(Bitwiseresult, "%s: %i", bitOpsTitle[data4.bitOps], data4.result);
    return Bitwiseresult;
}