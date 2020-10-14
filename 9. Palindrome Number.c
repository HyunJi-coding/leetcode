

bool isPalindrome(int x) {
	int digits[10];

	if (x<0) {
		return false;
	}

	int Index = 0;
	while (x != 0) {
		digits[Index] = x % 10;
		x /= 10;
		Index++;
	}
	int i = 0, j = Index - 1;
	while (i<j) {
		if (digits[i] != digits[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

/*
bool isPalindrome(int x){
char str[1000];
sprintf(str, "%d", x);
int len = strlen(str);
if (x < 0) {return false;}
for (int i=0; i <= (len/2); i++) {
if (str[i] == str[len-i-1])
continue;
return false;
}
return true;
}
*/
