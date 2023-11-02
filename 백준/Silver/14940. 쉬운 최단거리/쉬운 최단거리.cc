#include <iostream>
#include<queue>
#include<cstring>
using namespace std;

int graph[1001][1001] = {0,};
int visited[1001][1001] = { 0, };
int result[1001][1001] = { 0, };
int N, M;
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
queue<pair<int, int>> q;

void bfs(int x,int y) {
	q.push(make_pair(y, x));
	result[y][x] = 0;
	visited[y][x] = 1;
	while (!q.empty()) {
		int ry = q.front().first;
		int rx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ux = rx + dx[i], uy = ry + dy[i];
			if (ux <0 || uy<0 || ux>M || uy>N) continue;

			if (graph[uy][ux] == 0) continue;

			if (!visited[uy][ux]) {
				q.push(make_pair(uy, ux));
				result[uy][ux] = result[ry][rx] + 1;
				visited[uy][ux] = 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	int x = 0, y = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int value;
			cin >> value;
			graph[i][j] = value;
			if (value == 2) {
				y = i;
				x = j;
			}
			
		}
	}
	memset(result, -1, sizeof(result));
	bfs(x, y);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (graph[i][j] == 0) cout << graph[i][j] << ' ';
			else cout << result[i][j]<<' ';
		}
		cout << '\n';
	}
}