#include <iostream>
#include<vector>
#include<cstring>
using namespace std;

int V;
int endPoint = 0;
vector<pair<int, long>> graph[100001];
int visited[100001] = { 0, };
long result = 0;

void dfs(int node, long len) {
	if (visited[node]) return;

	visited[node] = 1;
	if (result < len) {
		result = len;
		endPoint = node;
	}
	for (int i = 0; i < graph[node].size(); i++)
		dfs(graph[node][i].first, len + graph[node][i].second);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;
	for (int i = 0; i < V; i++) {
		int go, to, value;
		cin >> go;
		while (true) {
			cin >> to;
			if (to == -1) break;
			cin >> value;
			graph[go].push_back(make_pair(to, value));
			graph[to].push_back(make_pair(go, value));
		}
	}
	dfs(1, 0);
	result = 0;
	memset(visited, 0, sizeof(visited));
	dfs(endPoint, 0);
	cout << result << '\n';	

}