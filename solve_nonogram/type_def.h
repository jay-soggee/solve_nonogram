#ifndef TYPEDEF_H
#define TYPEDEF_H



typedef struct FourCells
{
	unsigned char is_empty_1 : 1;
	unsigned char is_filled_1 : 1;
	unsigned char is_empty_2 : 1;
	unsigned char is_filled_2 : 1;
	unsigned char is_empty_3 : 1;
	unsigned char is_filled_3 : 1;
	unsigned char is_empty_4 : 1;
	unsigned char is_filled_4 : 1;
} fcell;



typedef struct LineClues
{
	int size;
	int* clues;
} lineclues;



#endif