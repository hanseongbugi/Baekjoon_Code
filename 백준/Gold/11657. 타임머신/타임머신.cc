#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 2100000000
int N, M;
vector<pair<int,int>> graph[501];
long long dist[501];
bool cycle;

void BF() {
    for(int i = 0;i<=N;i++)
        dist[i] = INF;

	dist[1] = 0;

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < graph[i].size(); j++) {
				int next = graph[i][j].first;
				int nextcost = graph[i][j].second;

				if (dist[i] != INF && dist[next] > dist[i] + nextcost) {
					dist[next] = dist[i] + nextcost;
					if (k == N) cycle = true;
				}
			}
		}
	}
	if (cycle) cout << -1;
	else {
		for (int i = 2; i <= N; i++)
			cout << (dist[i] != INF ? dist[i] : -1) << "\n";
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    int a, b, c;
    for(int i = 0;i<M;i++){
        cin>>a>>b>>c;
        graph[a].push_back({b, c});
    }
    BF();
}   