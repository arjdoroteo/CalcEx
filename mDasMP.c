#define SINGULARITY         ( 1U )
#include "mDasMP.h"
#include <stdio.h>

int addition( int inputA, int inputB )
{
    return ( inputA + inputB );
}

int subtraction( int inputA, int inputB )
{
    int result;
    if( inputA > inputB )
    {
        result = ( inputA - inputB );
    }
    else
    {
        result = ( inputB - inputA );
    }

    return result;
}

int multiplication( int inputA, int inputB )
{
    return ( inputA * inputB );
}

int division( int inputA, int inputB )
{
    int result;

    if( inputA > inputB )
    {
        result = (int)( inputA / inputB );
    }
    else
    {
        result = (int)( inputB / inputA );
    }
    
    return result;
}

int modulo( int inputA, int inputB )
{
    return ( inputA % inputB );
}

int power( int inputA, int inputB )
{
    int result = inputA;

    if( SINGULARITY < inputB )
    {
        inputB -= SINGULARITY;
        result *= power( inputA, inputB );
    }

    return result;
}

t_mathOpsData data =
{
    .inputA = 0,
    .inputB = 0,
    .mathOps = INVALID_mathOps,
    .result = 0,
};

// Mathresult is the container for the combined operation title and result which will be returned to add node function
char Mathresult[50];

const char* mathCase ()
{ 
    char mathOps = 'A'; // where did A come from?
    printf("Math Operand: ");
    scanf( " %c", &mathOps );
        
    switch( mathOps )
    {
        case '+':
        {
            data.mathOps = ADDITION;
        }
        break;
        case '-':
        {
            data.mathOps = SUBTRACTION;
        }
        break;
        case '*':
        {
            data.mathOps = MULTIPLICATION;
        }
        break;
        case '/':
        {
            data.mathOps = DIVISION;
        }
        break;
        case '%':
        {
            data.mathOps = MODULO;
        }
        break;
        case '^':
        {
            data.mathOps = POWER;
        }
        break;
        default:
        {
            data.mathOps = INVALID_mathOps;
        }
        break;
        }

        if( INVALID_mathOps > data.mathOps )
        {
            printf("Input A: ");
            scanf( "%i", &data.inputA );
            printf("Input B: ");
            scanf( "%i", &data.inputB );
            data.result = mathOpsHandlerList[data.mathOps]( data.inputA, data.inputB );
            printf("Operation: %s, Result: %i\n", mathOpsTitle[data.mathOps], data.result);
            scanf("%c", &mathOps);
            
        }   
    
    
    // converted to string along with other operations for uniformity
    sprintf(Mathresult, "%s: %i", mathOpsTitle[data.mathOps], data.result);
    
    return Mathresult;
    }
