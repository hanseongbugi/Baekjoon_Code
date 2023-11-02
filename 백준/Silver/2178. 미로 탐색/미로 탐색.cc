#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int visited[101][101];
int N, M;
char graph[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
vector<int> v;
queue<pair<pair<int,int>, int>> q;

void bfs() {
	q.push(make_pair(make_pair(0, 0), 1));
	visited[0][0] = 1;
	
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int counter = q.front().second;
		q.pop();

		if (x == N - 1 && y == M - 1) {
			v.push_back(counter);
		}

		for (int i = 0; i < 4; i++) {
			int ux = x + dx[i], uy = y + dy[i];

			if (ux < 0 || uy<0 || ux>N || uy>M) continue;

			if (graph[ux][uy] == '0') continue;

			if (!visited[ux][uy] && graph[ux][uy] == '1') {
				visited[ux][uy] = 1;
				q.push(make_pair(make_pair(ux, uy), counter+1));
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
		}
	}

	bfs();
	sort(v.begin(), v.end());
	cout << v[0] << '\n';
}