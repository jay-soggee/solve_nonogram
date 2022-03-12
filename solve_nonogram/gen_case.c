#include <stdlib.h>
#include "gen_case.h"
#include "check_case.h"

#ifdef DEBUG
#include <stdio.h>
#endif


void GenCase(clues line_clue, unsigned int nonogram_size) {

	unsigned int movable_padding = nonogram_size;
	for (unsigned int i = 0; i < line_clue.q; i++)
		movable_padding -= line_clue.clue[i];
	movable_padding -= line_clue.q - 1;

	
	unsigned int case_size = 0;
	int** case_mat = CombinationChecker(line_clue.q + 1, movable_padding, &case_size);

#ifdef DEBUG
	for (unsigned int i = 0; i < case_size; i++) {
		for (unsigned int j = 0; j < movable_padding; j++)
			printf("%2d", case_mat[i][j]);
		printf("\n");
	}
#endif

}

