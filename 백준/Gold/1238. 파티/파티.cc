#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M, X;
vector<pair<int,int>> graph[1001];
int dist[1001];
int answer = 0;
int result = 0;

// 가중치가 모두 양수이므로 다익스트라 사용 
void dijk(int start, int vertex){
    for(int i = 0;i<=N;i++)
        dist[i] = 987654321;
        
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if(cur == vertex){
            result = dist[cur];
            break;
        }
        
        
        for(int i = 0;i<graph[cur].size();i++){
            int next = graph[cur][i].first;
            int wieght = cost + graph[cur][i].second;

            if(dist[next] > wieght){
                pq.push({-wieght, next});
                dist[next] = wieght;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M>>X;
    int ans1, ans2, ans;
    ans = 0;
    int a, b, t;
    for (int i = 0; i < M;i++){
        cin >> a >> b >> t;
        graph[a].push_back({b, t});
    }
    for (int i = 1; i <= N;i++){
        dijk(i, X); // 가는 길 최단 거리 
        ans1 = result; 
        dijk(X, i); // 오는 길 최단 거리
        ans2 = result;
        if(answer < ans1+ans2)
            answer = ans1 + ans2; // 합
    }
    cout << answer << '\n'; // 최단 거리 출력

}   