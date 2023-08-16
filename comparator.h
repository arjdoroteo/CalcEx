typedef enum
{
    GREATER,
    LESSER,
    MAX_comparatorOps,
    INVALID_comparatorOps = MAX_comparatorOps

}t_comparatorOps;

typedef struct 
{
    int inputA;
    int inputB;
    int result;
    t_comparatorOps comparatorOps;
}t_comparatorOpsData;

typedef int ( *comparatorOpsHandler )( int inputA, int inputB );

int greater( int inputA, int inputB );
int lesser( int inputA, int inputB );

comparatorOpsHandler comparatorOpsHandlerList[MAX_comparatorOps] =
{
    [GREATER]  = &greater,
    [LESSER]   = &lesser,
};

const char* comparatorOpsTitle[MAX_comparatorOps] =
{
    [GREATER]        = "GREATER",
    [LESSER]         = "LESSER",
};


