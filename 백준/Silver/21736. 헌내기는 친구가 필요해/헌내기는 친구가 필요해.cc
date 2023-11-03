#include <iostream>
#include<queue>
using namespace std;

char graph[601][601];
int visited[601][601] = { 0, };
int N, M, counter = 0;
int dx[] = { 0,0,1,-1 };
int dy[] = { -1,1,0,0 };
queue<pair<int, int>> q;

void bfs(int x,int y) {
	q.push(make_pair(y, x));
	visited[y][x] = 1;
	while (!q.empty()) {
		int ny = q.front().first;
		int nx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int uy = ny + dy[i];
			int ux = nx + dx[i];

			if (uy < 0 || ux < 0 || uy>=N || ux>=M) continue;
			if (graph[uy][ux] == 'X') continue;

			if (!visited[uy][ux]) {
				q.push(make_pair(uy, ux));
				visited[uy][ux] = 1;
				if (graph[uy][ux] == 'P') counter += 1;
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
			char value;
			cin >> value;
			graph[i][j] = value;
			if (value == 'I') {
				x = j;
				y = i;
			}
		}
	}
	bfs(x, y);
	if (counter == 0) cout << "TT" << '\n';
	else cout<<counter<<'\n';
}