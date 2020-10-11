int singleNonDuplicate(int* nums, int numsSize) {
	int i;
	for (i = 1; i<numsSize; i += 2)
		if (nums[i] != nums[i - 1])
			return nums[i - 1];
	return nums[numsSize - 1];
}