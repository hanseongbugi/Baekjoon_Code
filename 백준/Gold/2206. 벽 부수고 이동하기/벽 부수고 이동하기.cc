#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N, M;
int answer = -1;
string graph[1001];
int visited[1001][1001][2];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(){
    queue<pair<pair<int,int>,int>> q; // y, x, dir
    q.push({{0,0},1,});
    visited[0][0][1] = 1;

    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int block = q.front().second;
        q.pop();
        if(y == N - 1 && x == M - 1){
            answer = visited[y][x][block];
            return;
        }
        for(int i = 0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny > N - 1 || nx < 0 || nx > M -1)
                continue;
            // 벽이고 뚫을 수 있을 때
            if(graph[ny][nx] == '1' && block){
                q.push({{ny,nx},0});
                visited[ny][nx][block - 1] = visited[y][x][block] + 1;
            }
            else if(graph[ny][nx] == '0' && visited[ny][nx][block] == 0){
                q.push({{ny,nx},block});
                visited[ny][nx][block] = visited[y][x][block] + 1;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    for(int i = 0;i<N;i++){
        cin>>graph[i];
    }
    bfs();

    cout<<answer;
}