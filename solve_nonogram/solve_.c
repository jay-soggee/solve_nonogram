#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void CombiationChecker(int n, int r);


int SolveThisLine(lineclues line_clues, unsigned int numof_cells) {

	// 예외 : 단서가 없을때.


	int movable_padding = numof_cells;

	for (unsigned int i = 0; i < line_clues.quantity; i++)
	{
		movable_padding -= line_clues.clues[i];
	}

	movable_padding -= line_clues.quantity - 1;

	int n = movable_padding + line_clues.quantity;
	int r = line_clues.quantity;

	CombiationChecker(n, r);
}

void CombiationChecker(int n, int r) {

	int* cookie_arr = (int*)calloc(r + 1, sizeof(int));
	int count = 0;

	while (1) {

		count++;


		for (unsigned int i = 0; i < r + 1; i++)
		{
			printf("%d ", cookie_arr[i]);
		}
		printf("\n");


		cookie_arr[0]++;

		for (int i = 0; i < r; i++) {

			if (cookie_arr[i] > (n - r)) {

				cookie_arr[i + 1]++;

			}
		}

		for (int i = r - 1; i >= 0; i--) {

			if (cookie_arr[i] > (n - r)) {

				// cookie_arr[i + 1]++;

				for (int j = i; j >= 0; j--)
				{
					cookie_arr[j] = cookie_arr[i + 1];
				}

				break;
			}
		}

		if (cookie_arr[r]) break;


	}

	free(cookie_arr);
}