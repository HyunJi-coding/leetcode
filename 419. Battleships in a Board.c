int countBattleships(char** board, int boardSize, int* boardColSize) {
	int i, j;
	int cnt = 0;

	for (i = 0; i < boardSize; i++) {
		for (j = 0; j < boardColSize[0]; j++) {
			if ((board[i][j] == 'X') && (i == 0 || board[i - 1][j] == '.') && (j == 0 || board[i][j - 1] == '.'))
				cnt++;
		}
	}
	
	return cnt;
}
