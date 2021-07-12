#include "../lib/w16.h"
#include <stdlib.h>
#include <stdio.h>

#ifndef W16_SYNTAX_H
#define W16_SYNTAX_H

// syntax structure from the parser
struct Syntax{
    int inst;
    int reg_a;
    int reg_b;
    int imm16;
};

enum Token_Type{
    reg,
    inst,
    imm
};

// token structure for the scanner
struct Token{
    int type;
    int val;
};

#endif // W16_SYNTAX_H