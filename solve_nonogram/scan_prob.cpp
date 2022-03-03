#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "main.h"


void TestPrintScaned(unsigned int numof_lines, lineclues* line_clues);



int ScanProblem(unsigned int* _numof_cols,unsigned int* _numof_rows, lineclues* col_clues, lineclues* row_clues) {
	
	
	unsigned int maxnumof_col_clues;
	unsigned int maxnumof_row_clues;

	scanf("%d", _numof_cols);
	scanf("%d", &maxnumof_col_clues);
	scanf("%d", _numof_rows);
	scanf("%d", &maxnumof_row_clues);

	unsigned int numof_cols = *_numof_cols;
	unsigned int numof_rows = *_numof_rows;



	if (numof_cols > MAX_LINES ||
		numof_rows > MAX_LINES ||
		maxnumof_col_clues > MAX_CLUES ||
		maxnumof_row_clues > MAX_CLUES)
	{
		return ERR_INVALID_NONOGRAM;
	}

	

	col_clues = (lineclues*)malloc(sizeof(lineclues) * numof_cols);

	row_clues = (lineclues*)malloc(sizeof(lineclues) * numof_rows);

	if (!col_clues && !row_clues) {
		free(row_clues);
		free(col_clues);
		return ERR_MALLOC_FAILED;
	}



	int* temp_clues = (int*)malloc(sizeof(int) * maxnumof_col_clues);

	for (unsigned int i = 0; i < numof_cols; i++)
	{

		for (unsigned int l = 0; l < maxnumof_col_clues; l++)
		{
			temp_clues[l] = 0;
		}



		unsigned int numof_clues = 0;

		for (unsigned int j = 0; j < maxnumof_col_clues + 1; j++)
		{
			int clue;

			scanf("%d", &clue);

			if (clue == 0) break;

			numof_clues++;

			temp_clues[j] = clue;
		}



		col_clues[i].size = numof_clues;

		col_clues[i].clues = (int*)malloc(sizeof(int) * numof_clues);

		for (unsigned int k = 0; k < numof_clues; k++)
		{
			col_clues[i].clues[k] = temp_clues[k];
		}

	}
	free(temp_clues);



	temp_clues = (int*)malloc(sizeof(int) * maxnumof_row_clues);

	for (unsigned int i = 0; i < numof_rows; i++)
	{

		for (unsigned int l = 0; l < maxnumof_row_clues; l++)
		{
			temp_clues[l] = 0;
		}



		unsigned int numof_clues = 0;

		for (unsigned int j = 0; j < maxnumof_row_clues + 1; j++)
		{
			int clue;

			scanf("%d", &clue);

			if (clue == 0) break;

			numof_clues++;

			temp_clues[j] = clue;
		}



		row_clues[i].size = numof_clues;

		row_clues[i].clues = (int*)malloc(sizeof(int) * numof_clues);

		for (unsigned int k = 0; k < numof_clues; k++)
		{
			row_clues[i].clues[k] = temp_clues[k];
		}

	}
	free(temp_clues);
	temp_clues = NULL;


	TestPrintScaned(numof_cols, col_clues);
	TestPrintScaned(numof_rows, row_clues);

}






void TestPrintScaned(unsigned int numof_lines, lineclues* line_clues) {
	puts("");
	for (size_t i = 0; i < numof_lines; i++)
	{
		for (size_t j = 0; j < line_clues[i].size; j++)
		{
			printf("%d ", line_clues[i].clues[j]);
		}
		puts("");
	}
	puts("");
}
