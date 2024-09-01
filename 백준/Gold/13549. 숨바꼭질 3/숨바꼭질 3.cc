#include <iostream>
#include <queue>
using namespace std;

int N, K;
int answer = 987654321;
bool visited[100001];

void bfs(){
    queue<pair<int,int>>q;
    q.push({N,0});

    while(!q.empty()){
        int now = q.front().first;
        int time = q.front().second;
        q.pop();
        visited[now] = true;
        if(now == K){
            answer = min(answer, time);
        }

        if(now + 1 <= 100000 && !visited[now + 1]){
            q.push({now + 1, time + 1});
        }
        if(now - 1 >= 0 && !visited[now - 1]){
            q.push({now - 1, time + 1});
        }
        if(now * 2 <= 100000 && !visited[now * 2]){
            q.push({now * 2, time});
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>K;
    bfs();
    cout<<answer;
}