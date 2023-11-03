#include <iostream>
#include<queue>
#include<cstring>
using namespace std;

char graph[101][101] = { 0, };
int visited[101]= { 0, };
int N, M, counter = 0;
queue<int> q;

void bfs() {
	q.push(1);
	visited[1] = 1;

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i <= N; i++) {
			if (!graph[now][i]) continue;
			if (!visited[i]) {
				q.push(i);
				visited[i] = 1;
				counter += 1;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int go, to;
		cin >> go >> to;
		graph[go][to] = 1;
		graph[to][go] = 1;
	}
	bfs();
	cout << counter << '\n';
}