#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int graph[8][8];
int answer = 0;
int temp[8][8];

void copyGraph(int a[8][8], int b[8][8]){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++)
            a[i][j] = b[i][j];
    }
}

void bfs(){
    int spread[8][8];
    copyGraph(spread, temp);
    queue<pair<int,int>> q;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(spread[i][j] == 2)
                q.push({i,j});
        }
    }

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;

        q.pop();
        for(int i = 0;i<4;i++){
            int uy = y + dy[i];
            int ux = x + dx[i];
            if(uy < 0 || uy >= N || ux < 0 || ux >=M)
                continue;
            
            if(spread[uy][ux] == 0){
                spread[uy][ux] = 2;
                q.push({uy,ux});
            }
        }
    }
    int cnt = 0;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(spread[i][j] == 0)
                cnt++;
        }
    }
    answer = max(answer, cnt);
}
void dfs(int num){
    if(num == 3){
        bfs();
        return;
    }

    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(temp[i][j] == 0){
                temp[i][j] = 1;
                dfs(num + 1);
                temp[i][j] = 0;
            }
        }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++)
            cin>>graph[i][j];
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(graph[i][j] == 0){
                copyGraph(temp, graph);
                temp[i][j] = 1;
                dfs(1);
                temp[i][j] = 0;
            }
        }
    }
    cout<<answer;
}   