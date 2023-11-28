#include <iostream>
#include<vector>
#include<cstring>
using namespace std;

int N;
vector<pair<int, int>> graph[10001];
int visited[10001]= { 0, };
int result = 0;
int endPoint = 0;

void dfs(int node, int len) {
	if (visited[node]) return;

	visited[node] = 1;
	
	if (result < len) {
		result = len;
		endPoint = node;
	}

	for (int i = 0; i < graph[node].size(); i++) {
		dfs(graph[node][i].first, len + graph[node][i].second);
	}
}

int main()
{
	cin >> N;
	int go, to, value;
	for (int i = 0; i < N-1; i++) {
		cin >> go >> to >> value;
		graph[go].push_back(make_pair(to, value));
		graph[to].push_back(make_pair(go, value));
	}
	dfs(1, 0);
	result = 0;
	memset(visited, 0, sizeof(visited));
	dfs(endPoint, 0);
	cout << result << '\n';
}
