int climbStairs(int n) {
	int ret = 0;
	int fn_1 = 1;
	int fn_2 = 1;
	int i;

	if (n == 0) return 1;
	if (n == 1) return 1;

	for (i = 2; i <= n; i++) {
		ret = fn_1 + fn_2;
		fn_2 = fn_1;
		fn_1 = ret;
	}

	return ret;
}