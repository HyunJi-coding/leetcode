#include <stdio.h>

int coinChange(int* coins, int coinsSize, int amount) {
	int i, j; 
	int *a = malloc(sizeof(int)*(amount + 1));

	for (i = 1; i <= amount; i++) {
		a[i] = NULL;
		for (j = 0; j<coinsSize; j++) {
			if (coins[j] > i)
				continue; else if (i == coins[j]) {
				a[i] = 1; break;
			}
				else if (a[i - coins[j]] == 0)
					continue;
			if (a[i]) {
				if (a[i]>a[i - coins[j]] + 1)
					a[i] = a[i - coins[j]] + 1; else
					a[i] = a[i];
			}
			else
				a[i] = a[i - coins[j]] + 1;
		}
	}

	if (amount == NULL) {
		return 0;
	}

	if (i = a[amount]) {
		i = a[amount];
	}
	else i = -1;
	return i;
}


int main() {
	
	int coins[5] = {1,2,5};
	int coinsize= 3;
	int amount= 11;

	printf("output: %d", coinChange(coins, coinsize, amount));

	

}