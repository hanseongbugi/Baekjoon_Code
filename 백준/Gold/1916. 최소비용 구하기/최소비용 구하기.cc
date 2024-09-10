#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, start, dest;
int dist[1001];
vector<pair<int,int>> graph[1001];

void dijk(){
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    dist[start] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if(dist[cur] < cost)
            continue;
        
        for(int i = 0;i<graph[cur].size();i++){
            int next = graph[cur][i].first;
            int weight = cost + graph[cur][i].second;
            if(dist[next] > weight){
                dist[next] = weight;
                pq.push({-weight, next});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    int go, to, weight;
    for(int i = 0;i<M;i++){
        cin>>go>>to>>weight;
        graph[go].push_back({to,weight});
    }
    cin>>start>>dest;

    for(int i = 0;i<=N;i++)
        dist[i] = 987654321;

    dijk();

    cout<<dist[dest];

}   