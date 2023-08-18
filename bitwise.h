typedef enum
{
    SHIFTRIGHT,
    SHIFTLEFT,
    ANDNUM,
    ORNUM,
    XORNUM,
    NOTNUM,
    MAX_bitOps,
    INVALID_bitOps = MAX_bitOps
} t_bitOps;


typedef struct
{
    int inputA;
    int inputB;
    int result;
    t_bitOps bitOps;
} t_bitOpsData;


typedef int ( *bitOpsHandler )( int intputA, int inputB ); 



int shiftRight( int inputA, int inputB );
int shiftLeft( int inputA, int inputB );
int andnum( int inputA, int inputB );
int ornum( int inputA, int inputB );
int xornum( int inputA, int inputB );
int notnum( int inputA, int inputB );

bitOpsHandler bitOpsHandlerList[MAX_bitOps] =
{
    [SHIFTRIGHT]          = &shiftRight,
    [SHIFTLEFT]           = &shiftLeft,
    [ANDNUM]              = &andnum,
    [ORNUM]               = &ornum,
    [XORNUM]              = &xornum,
    [NOTNUM]              = &notnum,
};

const char* bitOpsTitle[MAX_bitOps] =
{
    [SHIFTRIGHT]         = "SHIFT RIGHT",
    [SHIFTLEFT]          = "SHIFT LEFT",
    [ANDNUM]             = "AND",
    [ORNUM]              = "OR",
    [XORNUM]             = "XOR",
    [NOTNUM]             = "NOT",
};



