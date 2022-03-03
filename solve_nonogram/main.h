#ifndef MAIN_H
#define MAIN_H

#include "type_def.h"


#define ERR_INVALID_NONOGRAM -1
#define ERR_MALLOC_FAILED -2

#define MAX_LINES 128
#define MAX_CLUES 64


int ScanProblem(
	unsigned int* numof_cols,
	unsigned int* numof_rows,
	lineclues* col_clues, 
	lineclues* row_clues);



#endif