#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2000000000;

int N, M;
int st, en;
int dist[1001];
int route[1001];
vector<pair<int,int>> graph[1001];
vector<int> answer;

void dijk(){
    // dist 배열 초기화
    for(int i = 0;i<=N;i++)
        dist[i] = INF;
    
    priority_queue<pair<int, int>> pq;

    pq.push({0, st});
    dist[st] = 0;
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int now = pq.top().second;

        pq.pop();
        if(dist[now] < cost)
            continue;
        for(int i = 0;i<graph[now].size();i++){
            int next = graph[now][i].first;
            int nCost = graph[now][i].second + cost;

            if(nCost < dist[next]){
                route[next] = now;
                dist[next] = nCost;
                pq.push({-nCost, next});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    int a, b, c;
    for(int i =0;i<M;i++){
        cin>>a>>b>>c;
        graph[a].push_back({b, c});
    }
    cin>>st>>en;

    dijk();
    cout<<dist[en]<<'\n';

    int temp = en;
    while(temp){
        answer.push_back(temp);
        temp = route[temp];
    }
    cout<<answer.size()<<'\n';
    for(int i = answer.size() - 1;i>=0;i--)
        cout<<answer[i]<<' ';
    
}   
