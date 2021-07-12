# wing-16
16-bit custom architecture, light-weight computer

## Purpose

## ISA
registers, 16 bit each

--32 GP registers
0 - Zero register, Always 0
1-25 - GP
24:25 X 
26:27 Y
28:29 Z 
30:31 R - Multiply result or Divide Result:Remainder


--System registers

SYSFLAG
b0: Carry
b1: less than
b2: greater than
b3: borrow
b4:b15: reserved

PC

instruction

-- Memory:
16 bit addressing, 2 banks (instruction and RAM)

-- Instruction set Set
32 instructions
24-bit instructions, 8 bit opcode, 16 bit immediate(s)

-- Memory
0: Load; ld $src (implicite Z)
1: Store; st $dst (implicite Z)
-- Signed Math (unsigned at the proccessor level)
2: Add; add $dst, $a, $b
3: Add w/ carry; adc $dst, $a, $b
4: Add w/ Immediate; adi $dst, $a, imm16
5: Sub; sub $dst, $a, $b
6: Sub w/ carry; sbc $dst, $a, $b
7: Sub w/ Immediate; sbi $dst, $a, imm16
8: Multiply; mul $a, $b
?: Multiply Immediate; muli $a, imm16
9: Divide; div $a, $b
?: Divide Immediate; divi $a, imm16
-- Logical Operations
12: Shift right; lsr $dst, $src
13: Shift right w/ Immediate; lsri $dst
14: Shift left; lsl $dst
15: Shift Left w/ Immediate; lsli $dst
16: And; and $dst, $a, $b
17: Or; or $dst, $a, $b
18: Nor - can be used to make Not (nor foo, ~0 = ~foo ; nor $dst, $a, $b
-- Branching
19: Cmp; cmp $a, $b
1A: Breq; breq ${X,Y,Z}
1C: Jump Immediate; ji imm16
1D: Jump; j $a
--Vector
1E, 1F Reserved for vectors, might need to assign more bits in opcode for vectorinstructions
