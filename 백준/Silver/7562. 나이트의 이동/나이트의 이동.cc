#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int T, I;
int y, x;
int goalX, goalY;
bool visited[301][301];
int answer = 0;
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};

void bfs(){
    
    queue<pair<pair<int, int>,int>> q;
    q.push({{y, x}, 0});
    visited[y][x] = true;
    while(!q.empty()){
        int qy = q.front().first.first;
        int qx = q.front().first.second;
        int cost = q.front().second;
        q.pop();
        if(qy == goalY && qx == goalX){
            answer = cost;
            break;
        }

        for(int i = 0;i<8;i++){
            int ny = qy + dy[i];
            int nx = qx + dx[i];
        
            if(ny < 0 || ny >= I || nx < 0 || nx >= I)
                continue;
        
            if(!visited[ny][nx]){
                visited[ny][nx] = true;
                q.push({{ny, nx}, cost + 1});
            }
        }
    }
    
}  

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>I;

        cin>>y>>x;
        cin>>goalY>>goalX;

        memset(visited,false, sizeof(visited));
        answer = 0;

        bfs();
        cout<<answer<<'\n';
    }
}