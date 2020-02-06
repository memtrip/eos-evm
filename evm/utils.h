#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

unsigned char byteAt(unsigned int value, int pos);

void printOpcode(unsigned char value);

void printTier(unsigned char value);

void printOpcodeHex(unsigned char value);

void printInstruction(unsigned int value);

void printInstructionList();

#endif