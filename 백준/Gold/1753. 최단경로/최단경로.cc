#include<iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 100000000

int V, E;
int dist[20001];
vector<pair<int, int>> nodes[20001];

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;

	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < nodes[here].size(); i++) {
			int vist_cost = cost + nodes[here][i].first;

			if (vist_cost < dist[nodes[here][i].second]) {
				dist[nodes[here][i].second] = vist_cost;
				pq.push({ -vist_cost,nodes[here][i].second });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> V >> E;

	for (int i = 1; i <= V; i++)
		dist[i] = INF;

	int start;
	cin >> start;

	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		nodes[u].push_back({ w,v });
	}

	dijkstra(start);

	int count = 0;
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF" << '\n';
			continue;
		}
		cout << dist[i] << '\n';
	}

	return 0;
}