#include <iostream>
#include <cstring>
#include <vector>
#include<algorithm>
using namespace std;

int visited[26][26];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
vector<int> v;
int N, counter = 0, cnt=0;
char graph[26][26];

void dfs(int x,int y) {
	visited[x][y] = 1;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int ux = x + dx[i], uy = y + dy[i];
		if (ux < 0 || uy < 0 || ux >= N || uy >= N) continue;
		if (graph[ux][uy] == '0') continue;

		if (!visited[ux][uy] && graph[ux][uy] == '1') {
			dfs(ux, uy);
		}
	}
}

int main() {
	cin >> N;
	memset(graph, '0', sizeof(graph));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visited[i][j] && graph[i][j] == '1') {
				cnt = 0;
				dfs(i, j);
				counter++;
				v.push_back(cnt);
			}
		}
	}
	cout << counter << '\n';
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
}