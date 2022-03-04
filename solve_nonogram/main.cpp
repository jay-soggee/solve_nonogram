#include <stdio.h>
#include <stdlib.h>
#include "main.h"


int main() {

	puts("NONOGRAM CHEATER");


	unsigned int numof_cols;
	unsigned int numof_rows;
	lineclues* col_clues = 0;
	lineclues* row_clues = 0;


	switch (
		ScanProblem(
			&numof_cols,
			&numof_rows,
			col_clues,
			row_clues)
		) {

	case ERR_INVALID_NONOGRAM:
		return -1;

	case ERR_MALLOC_FAILED:
		return -2;

	default:
		break;
	}




	// free(line_clues);
	return 0;
}