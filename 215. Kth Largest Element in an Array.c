void bubble_sort(int arr[], int count) {
	int temp;
	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < count - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int findKthLargest(int* nums, int numsSize, int k) {
	bubble_sort(nums, numsSize);
	int output = nums[numsSize - k];
	return output;
}
