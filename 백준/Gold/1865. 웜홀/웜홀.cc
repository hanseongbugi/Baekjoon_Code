#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 987654321;
int TC, N, M, W;
vector<pair<pair<int, int>,int>> graph;
int dist[501];

void BF(){
    for(int i = 0;i<=N;i++)
        dist[i] = INF;
    
    for(int i = 0;i<N;i++){
        for(int j = 0;j<graph.size();j++){
            int now = graph[j].first.first;
            int to = graph[j].first.second;
            int cost = graph[j].second;

            if(dist[now] + cost < dist[to])
                dist[to] = dist[now] + cost;
        }
    }

    for(int i = 0;i<graph.size();i++){
        int now = graph[i].first.first;
        int to = graph[i].first.second;
        int cost = graph[i].second;

        if(dist[now] + cost < dist[to]){
            cout<<"YES"<<'\n';
            return;
        }
    }
    cout<<"NO"<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>TC;
    while(TC--){
        graph.clear();
        cin>>N>>M>>W;

        int S, E, T;
        for(int i = 0;i<M;i++){
            cin>>S>>E>>T;
            graph.push_back({{S, E}, T});
            graph.push_back({{E, S}, T});
        }
        for(int i = 0;i<W;i++){
            cin>>S>>E>>T;
            graph.push_back({{S,E},-T});
        }
        BF();
    }
}   