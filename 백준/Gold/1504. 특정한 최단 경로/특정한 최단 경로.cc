#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 200000000

int N, E, u, v;
vector<pair<int, int>> graph[801];
int dist[801];
bool visited[801];

void dijk(int st){
    // 1번에서 N번까지 이동
    // u와 v 정점을 반드시 거칠 것
    for(int i = 0;i<=N;i++)
        dist[i] = INF;

    priority_queue<pair<int, int>> pq;
    pq.push({0, st});
    dist[st] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(cost > dist[now])
            continue;

        for(int i = 0;i<graph[now].size();i++){
            int next = graph[now][i].first;
            int nCost = graph[now][i].second;

            if(dist[next] > nCost + cost){
                dist[next] = nCost + cost;
                pq.push({-dist[next], next});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>E;
    int a, b, c;
    for(int i = 0;i<E;i++){
        cin>>a>>b>>c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin>>u>>v;

    dijk(1);
    int to_u = dist[u];
    int to_v = dist[v];

    dijk(u);
    int u_to_v = dist[v];
    int u_to_N = dist[N];

    dijk(v);
    int v_to_N = dist[N];

    int result;
    result = min(INF, to_u + u_to_v + v_to_N);
    result = min(result, to_v + u_to_v + u_to_N);
    
    if(result >= INF)
        cout<<-1;
    else
        cout<<result;
}   