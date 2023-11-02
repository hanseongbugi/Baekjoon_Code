#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int result;
int graph[101] = { 0, };
int visited[101] = { 0, };
queue<pair<int, int>> q;

void bfs() {
	q.push(make_pair(1, 0));
	visited[1] = 1;
	while (!q.empty()) {
		int v = q.front().first;
		int c = q.front().second;
		q.pop();

		if (v == 100) {
			result = c;
			break;
		}
		c++;
		for (int i = 0; i < 6; i++) {
			int pos = v + (i + 1);
			if (pos > 100) continue;

			if (!visited[pos]) {
				if (graph[pos]) {
					q.push(make_pair(graph[pos], c));
					visited[graph[pos]] = 1;
				}
				else {
					q.push(make_pair(pos, c));
					visited[pos] = 1;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N + M; i++) {
		int index, value;
		cin >> index >> value;
		graph[index] = value;
	}
	bfs();
	cout << result << '\n';
}