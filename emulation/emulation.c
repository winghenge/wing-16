#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "emulation.h"
#include "../lib/w16.h"

// Maximum memory size for 16 bit addresses
#define MAX_MEM 65536

// How many arithmatic registers (R31:R0)
#define BASE_REG_COUNT 32

// How many system registers (Instruction, Sysflag, PC)
#define SYS_REG_COUNT 3

// How many total registers
#define REG_COUNT (SYS_REG_COUNT+BASE_REG_COUNT)

// Reg_Mem_Grow will dynamically grow the memory blocks of 
// Struct Memory instances up until their max size (Memory->Max_Size) has been reached
// Since we're using 16-bit addressable memory, and 16 bit addresses, we'd have to
// deal with a potential of 131k+ bytes of memory for both the instruction and RAM blocks
// so we are slightly increasing the computational complexity 
// to prevent taking up multiple killobytes of uneeded RAM on the host
// will double the size of the memory until max mem reached
// Returns 1 on no-growth nessisary, -1 if mem max has been reached, 0 on growth
int reg_mem_grow(struct Memory *mem){
    // check to see if we even need to grow the array
    if (mem->num < mem->size) return 1;

    // check to see if we are at maximum size
    if (mem->size >= mem->max_size) return -1;

    // have a tmp pointer to the old pointer array
    uint16_t **tmp = mem->block;

    // allocate a new array of 2x size
    mem->block = (uint16_t **) malloc (sizeof(uint16_t)*2*mem->size);

    // copy over the pointers from the old array
    // and allocate the new memory
    for (int i = 0; i < mem->size; i++){
        mem->block[i] = tmp[i];
        mem->block[mem->size + i] = (uint16_t *) malloc(sizeof(uint16_t));
    }

    // record the new size
    mem->size *= 2;

    // free the temporary array
    free(tmp);

    return 0;
}

// Reg_Mem_Alloc will initilize a memory structure
void reg_mem_alloc(struct Memory *mem, int base_size, int max_size){
    // remember this bank's memory configuration
    mem->size = size;
    mem->max_size = max_size;
    mem->num = 0;

    // allocate memory
    mem->block = (uint16_t **) malloc(sizeof(uint16_t *)*size);
    for (int i = 0; i < mem->size; i++){
        mem->block[i] = (uint16_t *) malloc(sizeof(uint16_t));
    }

    return;

}

struct Machine *init_machine(char *file){
    // allocate memory for the machine structure
    struct Machine *m = (struct Machine *) malloc(sizeof(struct Machine));

    // allocate the register memory
    reg_mem_alloc(m->reg, REG_COUNT, REG_COUNT);

    // Allocate the instruction block memory
    reg_mem_alloc(m->inst, 256, MAX_MEM);

    // Allocate the RAM block memory
    reg_mem_alloc(m->ram, 256, MAX_MEM);

    return m;
}

int boot_program(struct Machine *m, char *file){


    return 0;
}

int emulate(struct Machine *m){


    return 0;
}