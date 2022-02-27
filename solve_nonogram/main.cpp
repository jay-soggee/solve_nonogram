#include <iostream>
using namespace std;

#define MAX_LINES 128
#define MAX_CLUES 64


int main() {

	cout << "NONOGRAM CHEATER" << endl;



	/* 문제 입력받기 */



	// get how big nonogram is

	unsigned int numof_cols;
	unsigned int max_col_clues;
	unsigned int numof_rows;
	unsigned int max_row_clues;

	cin >> numof_cols;
	cin >> max_col_clues;
	cin >> numof_rows;
	cin >> max_row_clues;

	if (numof_cols > MAX_LINES ||
		numof_rows > MAX_LINES || 
		max_col_clues > MAX_CLUES || 
		max_row_clues > MAX_CLUES)
	{
		cout << "invalid nonogram" << endl;
		return -1;
	}



	// 2-dimentional memory space for clues in each row/col

	int** col_clue = (int**)malloc(sizeof(int*) * (numof_cols + 1));

	int** row_clue = (int**)malloc(sizeof(int*) * numof_rows);
	




	// get each coloumn clue

	int* temp_clues = (int*)malloc(sizeof(int) * max_col_clues);

	for (unsigned int i = 0; i < numof_cols; i++)
	{

		for (unsigned int l = 0; l < max_col_clues; l++)
		{
			temp_clues[l] = 0;
		}


		// get clue of this col into temporary space

		int numof_clues = 0;

		for (unsigned int j = 0; j < max_col_clues + 1; j++)
		{
			int clue;

			cin >> clue;

			if (clue == 0) break;

			numof_clues++;

			temp_clues[j] = clue;
		}


		// copy it

		col_clue[i] = (int*)malloc(sizeof(int) * numof_clues);

		for (unsigned int k = 0; k < numof_clues; k++)
		{
			col_clue[i][k] = temp_clues[k];
		}

	}
	free(temp_clues);



	// get each row clue

	temp_clues = (int*)malloc(sizeof(int) * max_row_clues);

	for (unsigned int i = 0; i < numof_rows; i++)
	{

		for (unsigned int l = 0; l < max_row_clues; l++) 
		{
			temp_clues[l] = 0;
		}


		// get clue of this row into temporary space

		int numof_clues = 0;

		for (unsigned int j = 0; j < max_row_clues + 1; j++)
		{
			int clue;

			cin >> clue;
			
			if (clue == 0) break;

			numof_clues++;

			temp_clues[j] = clue;
		}


		// copy it

		row_clue[i] = (int*)malloc(sizeof(int) * numof_clues);

		for (unsigned int k = 0; k < numof_clues; k++)
		{
			row_clue[i][k] = temp_clues[k];
		}

	}
	free(temp_clues);
	temp_clues = NULL;



	for (unsigned int i = 0; i < numof_cols; i++)
	{
		for (unsigned int j = 0; j < sizeof(*col_clue[i]) / sizeof(int*); j++)
		{

		}
	}



	// free(col_clue);
	// free(row_clue);
	return 0;
}