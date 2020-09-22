#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define false 0
#define true 1

bool wordPattern(char* pattern, char* str) {
	int len1 = strlen(pattern);

	int cut = 1;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ') {
			cut++;
		}
	}

	if (len1 != cut) {
		return false;
	}

	char *arr[30];
	for (int i = 0; i<30; i++) {
		arr[i] = '\0';
	}
	for (int i = 0; pattern[i] != 0; i++) {
		int size = 0;
		char *len2 = malloc(sizeof(char) * 26);
		int space = i;
		char *sptr = str;

		while (space) {
			if (*sptr == ' ') {
				space--;
			}
			sptr++;
		}
		for (int i = 0; sptr[i] != ' ' && sptr[i] != 0; i++){
			len2[i] = sptr[i];
			size++;
		}
		len2[size] = 0;
		if (arr[pattern[i] - 'a'] == '\0') {
			for (int j = 0; j<30; j++) {
				if (arr[j] != '\0') {
					if (strcmp(arr[j], len2) == 0) {
						return 0;
					}
				}
			}
			arr[pattern[i] - 'a'] = len2;
		}
		else {
			if (strcmp(arr[pattern[i] - 'a'], len2) != 0){
				return false;
			}
		}

	}
	return true;
}

int main(void) {
	char *pattern = "abba";
	char *str = "dog cat cat dog";
	bool result = wordPattern(pattern, str);

	printf("output : %d \n", result);

	return 0;
}

