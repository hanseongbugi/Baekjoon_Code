#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dist[51];
vector<pair<int,int>> graph[51];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    for(int i = 1;i<=N;i++)
        dist[i] = 987654321;
    for(int i = 0;i<road.size();i++){
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    
    priority_queue<pair<int,int>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    
    while(!pq.empty()){
        int cost = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        
        if(dist[now] < cost)
            continue;
        
        for(int i = 0;i<graph[now].size();i++){
            int next = graph[now][i].first;
            int nCost = graph[now][i].second;
            
            if(cost + nCost < dist[next]){
                dist[next] = cost + nCost;
                pq.push({-dist[next], next});
            }
        }
    }
    for(int i = 1;i<=N;i++){
        if(dist[i] <= K)
            answer++;
    }
    return answer;
}