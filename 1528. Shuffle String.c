char * restoreString(char * s, int* indices, int indicesSize) {
	int i;
	char result[indicesSize];
	for (i = 0; i<indicesSize; i++) {
		result[indices[i]] = s[i];
	}
	for (i = 0; i<indicesSize; i++) {
		s[i] = result[i];
	}
	return s;
}