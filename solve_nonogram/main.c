#include "scan_clues.h"
#include "data.h"
#include "gen_case.h"


int main() {

	int numof_col = 0;
	int numof_row = 0;

	if (ScanNonoSize(&numof_col, &numof_row))
		return -1;

	clues* col_clue_arr = (clues*)ScanClues(numof_col);
	clues* row_clue_arr = (clues*)ScanClues(numof_row);

	GenCase(col_clue_arr[0], numof_row);

	FreeClues(col_clue_arr, numof_col);
	FreeClues(row_clue_arr, numof_row);

	return 0;
}