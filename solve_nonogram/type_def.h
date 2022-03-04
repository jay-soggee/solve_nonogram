#ifndef TYPEDEF_H
#define TYPEDEF_H



typedef struct byteCell {

	char is_empty_1 : 1;
	char is_filled_1 : 1;

	char is_empty_2 : 1;
	char is_filled_2 : 1;

	char is_empty_3 : 1;
	char is_filled_3 : 1;

	char is_empty_4 : 1;
	char is_filled_4 : 1;

} bcell;


typedef struct wordCell {

	bcell cells_1;
	bcell cells_2;
	bcell cells_3;
	bcell cells_4;

} cellint;



typedef struct LineClues {

	int quantity;
	int* clues;

} lineclues;



#endif