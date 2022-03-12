#ifndef SCANCLUES
#define SCANCLUES

//#define DEBUG

#include "data.h"

#define MAXSIZE 128


int ScanNonoSize(int* m, int* n);
void* ScanClues(unsigned int n);
void FreeClues(clues* line_clue_arr, unsigned int n);


#endif