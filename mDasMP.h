typedef enum
{
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    MODULO,
    POWER,
    MAX_mathOps,
    INVALID_mathOps = MAX_mathOps
} t_mathOps;


typedef struct
{
    int inputA;
    int inputB;
    int result;
    t_mathOps mathOps;
} t_mathOpsData;


typedef int ( *mathOpsHandler )( int intputA, int inputB ); // Function pointer?? 



int addition( int inputA, int inputB );
int subtraction( int inputA, int inputB );
int multiplication( int inputA, int inputB );
int division( int inputA, int inputB );
int modulo( int inputA, int inputB );
int power( int inputA, int inputB );

mathOpsHandler mathOpsHandlerList[MAX_mathOps] =
{
    [ADDITION]          = &addition,    //
    [SUBTRACTION]       = &subtraction,
    [MULTIPLICATION]    = &multiplication,
    [DIVISION]          = &division,
    [MODULO]            = &modulo,
    [POWER]             = &power,
};

const char* mathOpsTitle[MAX_mathOps] =
{
    [ADDITION]          = "ADDITION",
    [SUBTRACTION]       = "SUBTRACTION",
    [MULTIPLICATION]    = "MULTIPLICATION",
    [DIVISION]          = "DIVISION",
    [MODULO]            = "MODULO",
    [POWER]             = "POWER",
};

