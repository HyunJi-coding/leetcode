#include <stdio.h>
#include <stdlib.h>

int** spiralMatrixIII(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes) {
	int dir, cur = 0, loop = 0;

	*returnSize = R * C;
	int **arr = malloc(sizeof(int*) **returnSize);
	*returnColumnSizes = malloc(sizeof(int) **returnSize);

	for (int i = 0; i < *returnSize; ++i) {
		(*returnColumnSizes)[i] = 2;
		arr[i] = malloc(sizeof(int) * 2);
	}


	arr[cur][0] = r0;
	arr[cur++][1] = c0;

	while (cur < *returnSize) {
		dir = loop % 4;

		for (int i = 0; i < (loop / 2) + 1; i++) {
			if (dir == 0) //0:오른쪽 1:아래 2:왼쪽 3:위
				c0++;
			else if (dir == 1)
				r0++;
			else if (dir == 2)
				c0--;
			else
				r0--;

			if (r0 >= 0 && r0 < R && c0 >= 0 && c0 < C) {
				arr[cur][0] = r0;
				arr[cur++][1] = c0;
			}
		}
		loop++;
	}
	return arr;
}
