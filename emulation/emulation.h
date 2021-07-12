#include "../lib/w16.h"
#include <stdint.h>

// Library to setup the basics of the Wing16 CPU
#ifndef EM_W16_H
#define EM_W16_H

struct Memory{
    int size;
    int max_size;
    int num;
    uint16_t **block;
};

struct Machine{
    struct Memory *inst;
    struct Memory *ram;
    struct Memory *reg;
};

struct Machine *init_machine(char *file);
int boot_program(struct Machine *m, char *file);
int emulate(struct Machine *m);

#endif //EM_W16_H