#include <stdio.h>
#include <stdlib.h>
#include "main.h"


int main() {

	puts("NONOGRAM CHEATER");

	unsigned int numof_cols;
	unsigned int numof_rows;
	lineclues* col_clues = { 0, };
	lineclues* row_clues = { 0, };


	int err;
	err = ScanProblem(
		&numof_cols,
		&numof_rows,
		col_clues, 
		row_clues);
	if (err < 0) return -1;





	// free(col_clue);
	// free(row_clue);
	return 0;
}