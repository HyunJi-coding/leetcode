

char * customSortString(char * S, char * T) {
	int i;
	int j;
	int count = 0;
	char temp;

	for (i = 0; i<strlen(S); i++)
	{
		for (j = 0; j<strlen(T); j++)
		{
			if (S[i] == T[j])
			{
				temp = T[count];
				T[count] = T[j];
				T[j] = temp;
				count++;
			}
		}
	}

	return T;
}