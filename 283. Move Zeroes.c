void moveZeroes(int* nums, int numsSize) {
	int zero = 0;

	for (int i = 0; i<numsSize; i++) {
		if (nums[i] == 0)
			zero++;
		else
			nums[i - zero] = nums[i];

	}
	for (int j = numsSize - zero; j<numsSize; j++) {
		nums[j] = 0;
	}
	return nums;
}