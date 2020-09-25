/**
* Note: The returned array must be malloced, assume caller calls free().
*/
void swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
	*returnSize = numsSize;

	int i, j, min;
	for (i = 0; i<numsSize - 1; i++) {
		min = i;
		for (j = i + 1; j<numsSize; j++) {
			if (nums[j]<nums[min])
				min = j;
		}
		swap(&nums[min], &nums[i]);
	}

	return nums;
}