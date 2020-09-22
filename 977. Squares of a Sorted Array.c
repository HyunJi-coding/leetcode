#include <stdio.h>

int lengthOfLastWord(char* s) {
	int length = strlen(s);
	int count = 0;
	int i = length - 1;

	for (; i >= 0; i--) {
		if (s[i] == ' ' && count != 0)
			break;
		else if (s[i] != ' ' || count != 0)
			count++;
	}


	return count;
}

int main() {
	char s[100];

	scanf("%s", s);
	printf("%d\n",lengthOfLastWord(s));
	
}