#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
int result = 987654321;
int board[11][11];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
bool visited[11][11];

void resetBoard(int y, int x) {
	visited[y][x] = false;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = false;
	}
}

int checkFlower(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (visited[ny][nx]) return -1;
	}
	int sum = board[y][x];
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		visited[ny][nx] = true;
		sum += board[ny][nx];
	}
	return sum;
}

void dfs(int y, int x, int counter, int cost) {
	if (counter == 3) {
		result = min(result, cost);
		return;
	}
	for (int i = y; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			if (visited[i][j])continue;
			int sum = checkFlower(i, j);
			if (sum != -1) {
				dfs(i, j, counter + 1, cost + sum);
				resetBoard(i, j);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	}

	
	for (int i = 1; i < N - 1; i++) {
		for (int j = 1; j < N - 1; j++) {
			int sum = checkFlower(i, j);
			dfs(i, j, 1, sum);
			resetBoard(i, j);
		}
	}
	cout << result << '\n';
	return 0;
}