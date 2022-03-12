#include <stdlib.h>


int** CombinationChecker(unsigned int n, unsigned int r, unsigned int* size) {

	int** case_mat = (int**)malloc(sizeof(int*) * 0);

	int* cookie_arr = (int*)calloc(r + 1, sizeof(unsigned int));
	unsigned int count = 0;
	do {

		count++;

		case_mat = (int**)realloc(case_mat, sizeof(int*) * count);
		case_mat[count - 1] = calloc(r, sizeof(unsigned int));
		for (unsigned int i = 0; i < r; i++) {
			case_mat[count - 1][i] = cookie_arr[i];
		}

		cookie_arr[0]++;
		for (unsigned int i = 0; i < r; i++) {
			if (cookie_arr[i] > n) {
				cookie_arr[i + 1]++;
			}
		}
		for (int i = r - 1; i >= 0; i--) {
			if (cookie_arr[i] > n) {
				for (int j = i; j >= 0; j--) {
					cookie_arr[j] = cookie_arr[i + 1];
				}
				break;
			}
		}
		if (cookie_arr[r]) break;

	} while (1);

	*size = count;
	return case_mat;

	free(cookie_arr);
}


int** ConverseCase(int** case_c, unsigned int n, unsigned int r) {




}