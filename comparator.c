#include <stdio.h>
#include "comparator.h"
int greater( int inputA, int inputB )
{
    if (inputA > inputB)
    {
        return inputA;
    }else
    {
        return inputB;
    };

};

int lesser( int inputA, int inputB )
{
    if (inputA < inputB)
    {
        return inputA;
    }else
    {
        return inputB;
    };
};

t_comparatorOpsData data3 =
{
    .inputA = 0,
    .inputB = 0,
    .comparatorOps = INVALID_comparatorOps,
    .result = 0,
};

char Comparatorresult [50];

const char* comparatorCase(){

    char comparatorOps = 'A';
    printf("Choose Comparator: ");
    scanf( " %c", &comparatorOps );

    switch( comparatorOps )
    {
        case '>':
        {
            data3.comparatorOps = GREATER;
        }
        break;
        case '<':
        {
            data3.comparatorOps = LESSER;
        }
        break;
        default:
        {
            data3.comparatorOps = INVALID_comparatorOps;
        }
        break;
    }

    if( INVALID_comparatorOps > data3.comparatorOps )
    {
        printf("Input A: ");
        scanf( "%i", &data3.inputA );
        printf("Input B: ");
        scanf( "%i", &data3.inputB );
        data3.result = comparatorOpsHandlerList[data3.comparatorOps]( data3.inputA, data3.inputB );
        printf("Operation: %s, Result: %i\n", comparatorOpsTitle[data3.comparatorOps], data3.result);
        scanf("%c", &comparatorOps);
    }

    sprintf(Comparatorresult, "%s: %i", comparatorOpsTitle[data3.comparatorOps], data3.result);

    return Comparatorresult;
}