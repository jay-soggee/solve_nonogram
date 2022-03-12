#include <stdio.h>
#include <stdlib.h>
#include "scan_clues.h"


int ScanNonoSize(int* m, int* n) {

	scanf("%d %d", m, n);

	if (*m <= 0 ||
		*n <= 0 ||
		*m > MAXSIZE ||
		*n > MAXSIZE) {
		printf("Invalid Nonogram");
		return 1;
	}
	return 0;
}


void* ScanClues(unsigned int n) {

	clues* line_clue_arr = (clues*)malloc(sizeof(clues) * n);

	int* temp_arr = (int*)calloc(0, sizeof(unsigned int));
	for (unsigned int i = 0; i < n; i++) {

		unsigned int temp_count = 0;
		while (1) {

			unsigned int temp_clue = 0;
			scanf("%d", &temp_clue);

			if (temp_clue) {
				temp_count++;
				temp_arr = realloc(temp_arr, sizeof(int) * temp_count);
				temp_arr[temp_count - 1] = temp_clue;
			}
			else {
				line_clue_arr[i].q = temp_count;
				line_clue_arr[i].clue = (int*)malloc(sizeof(int) * temp_count);
				for (unsigned int j = 0; j < temp_count; j++) {
					line_clue_arr[i].clue[j] = temp_arr[j];
				}
				break;
			}
		}
	}
	free(temp_arr);

	return line_clue_arr;
}

void FreeClues(clues* line_clue_arr, unsigned int n) {
#ifdef DEBUG
	printf("\n");
#endif
	for (unsigned int i = 0; i < n; i++) {
#ifdef DEBUG
		for (unsigned int j = 0; j < line_clue_arr[i].q; j++)
			printf("%d ", line_clue_arr[i].clue[j]);
		printf("\n");
#endif
		free(line_clue_arr[i].clue);
	}

}