#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "main.h"



int SolveThisLine(lineclues line_clues, unsigned int numof_cells) {

	// 예외 : 단서가 없을때.


	int movable_padding = numof_cells;

	for (unsigned int i = 0; i < line_clues.quantity; i++)
	{
		movable_padding -= line_clues.clues[i];
	}

	movable_padding -= line_clues.quantity - 1;




	return 0;
}