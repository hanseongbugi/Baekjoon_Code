#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int board[19][19];
int result = 0;
int resultX, resultY;

bool rowCheck(int y, int x) {
	int color = board[y][x];

	for (int i = 1; i <= 4; i++) {
		if (board[y][x + i] != color) return false;
	}

	if (board[y][x - 1] == color || board[y][x + 5] == color) {
		return false;
	}
	return true;
}
bool colCheck(int y, int x) {
	int color = board[y][x];

	for (int i = 1; i <= 4; i++) {
		if (board[y + i][x] != color)return false;
	}
	if (board[y - 1][x] == color || board[y + 5][x] == color) return false;

	return true;
}

bool diagonalCheck1(int y, int x) {
	int color = board[y][x];
	
	for (int i = 1; i <= 4; i++) {
		if (board[y+i][x+i] != color) return false;
	}
	if (board[y - 1][x - 1] == color || board[y + 5][x + 5] == color) return false;
	return true;
}

bool diagonalCheck2(int y, int x) {
	int color = board[y][x];

	for (int i = 1; i <= 4; i++) {
		if (board[y - i][x + i] != color) return false;
	}
	if (board[y + 1][x - 1] == color || board[y - 5][x + 5] == color) return false;
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++)
			cin >> board[i][j];
	}
	
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (board[i][j] == 0)continue;

			if (rowCheck(i, j)) {
				result = board[i][j];
				resultY = i + 1;
				resultX = j + 1;
			}
			if (colCheck(i, j)) {
				result = board[i][j];
				resultY = i + 1;
				resultX = j + 1;
			}
			if (diagonalCheck1(i, j)) {
				result = board[i][j];
				resultY = i + 1;
				resultX = j + 1;
			}
			if (diagonalCheck2(i, j)) {
				result = board[i][j];
				resultY = i + 1;
				resultX = j + 1;
			}
		}
	}


	if (result != 0) {
		cout << result << '\n';
		cout << resultY  << ' ' << resultX << '\n';
	}
	else cout << result << '\n';

	
	return 0;
}