typedef enum
{
    DECIMAL2HEX,
    DECIMAL2BIN,
    HEX2BIN,
    HEX2DECIMAL,
    BIN2DECIMAL,
    BIN2HEX,
    MAX_converterOps,
    INVALID_converterOps = MAX_converterOps

}t_converterOps;

typedef struct 
{
    char* inputA;
    char* result;
    t_converterOps converterOps;
}t_converterOpsData;

typedef char* ( *converterOpsHandler )( char* intputA );

char* decimal2hex( char* inputA );
char* decimal2bin( char* inputA );
char* hex2bin( char* inputA );
char* hex2decimal( char* inputA );
char* bin2decimal( char* inputA );
char* bin2hex( char* inputA );

converterOpsHandler converterOpsHandlerList[MAX_converterOps] =
{
    [DECIMAL2HEX]   = &decimal2hex,
    [DECIMAL2BIN]   = &decimal2bin,
    [HEX2BIN]       = &hex2bin,
    [HEX2DECIMAL]   = &hex2decimal,
    [BIN2DECIMAL]   = &bin2decimal,
    [BIN2HEX]       = &bin2hex,

};
const char* converterOpsTitle[MAX_converterOps] =
{
    [DECIMAL2HEX]         = "DECIMAL2HEX",
    [DECIMAL2BIN]         = "DECIMAL2BIN",
    [HEX2BIN]             = "HEX2BIN",
    [HEX2DECIMAL]         = "HEX2DECIMAL",
    [BIN2DECIMAL]         = "BIN2DECIMAL",
    [BIN2HEX]             = "BIN2HEX",
};

