int* sortArrayByParityII(int* A, int ASize, int* returnSize) {
	*returnSize = ASize;
	int odd = 1;
	int even = 0;
	int* arr = malloc(sizeof(int)*ASize);
	for (int i = 0; i < ASize; i++)
	{
		if (A[i] % 2 == 0)
		{
			arr[even] = A[i];
			even += 2;
		}
		else
		{
			arr[odd] = A[i];
			odd += 2;
		}
	}
	return arr;
}