#include<iostream>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;

vector<pair<int, int>> nodes[300001];
int dist[300001];
int N, M, K, X;

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;

	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first; // 우선 순위 큐는 내림차순 정렬이 디폴트
		int here = pq.top().second;
		pq.pop();

		// 이미 최단 거리 정보가 있으면 무시
		if (dist[here] < cost) continue;

		for (int i = 0; i < nodes[here].size(); i++) {
			int vist_cost = cost + nodes[here][i].first;

			// here를 경유해서 가는게 더 빠르면 dist 갱신 후 push
			if (vist_cost < dist[nodes[here][i].second]) {
				dist[nodes[here][i].second] = vist_cost;
				pq.push({ -vist_cost,nodes[here][i].second });
				// 내림차순 정렬이라서 최소 값이 항상 앞에 오도록 음수 처리
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K >> X;

	for (int i = 1; i <= N; i++)
		dist[i] = INF;

	int start, end;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		nodes[start].push_back({ 1,end });
	}

	dijkstra(X);

	int count = 0;
	for (int i = 1; i <= N; i++) {
		if (dist[i] == K) {
			cout << i << '\n';
			count += 1;
		}
	}
	if (count == 0)cout << -1 << '\n';

	return 0;
}