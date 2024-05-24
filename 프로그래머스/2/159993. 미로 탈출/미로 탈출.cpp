#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int y, x;
int answer;
bool visited[101][101];

void bfs2(int my, int mx, vector<string> maps, int& answer){
    memset(visited, false, sizeof(visited));

    queue<pair<pair<int, int>, int>> q;
    q.push({{my, mx}, answer});
    answer = 987654321;
    visited[my][mx] = true;
    while(!q.empty()){
        int qy = q.front().first.first;
        int qx = q.front().first.second;
        int counter = q.front().second;
        q.pop();
        if(maps[qy][qx] == 'E'){
            answer = min(answer, counter);
            break;
        }
            
        for(int i = 0;i<4;i++){
            int uy = qy + dy[i];
            int ux = qx + dx[i];
            
            if(uy < 0 || uy >= y || ux < 0 || ux >= x || maps[uy][ux]=='X')
                continue;
            if(!visited[uy][ux]){
                visited[uy][ux] = true;
                q.push({{uy, ux}, counter+1});
            }
        }
    }
}

void bfs1(int my, int mx, vector<string> maps, int& answer){
    int exitX = 0, exitY = 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({{my, mx}, 0});
    visited[my][mx] = true;
    while(!q.empty()){
        int qy = q.front().first.first;
        int qx = q.front().first.second;
        int counter = q.front().second;
        q.pop();
        if(maps[qy][qx] == 'L'){
            answer = min(answer, counter);
            exitX = qx;
            exitY = qy;
            break;
        }
            
        for(int i = 0;i<4;i++){
            int uy = qy + dy[i];
            int ux = qx + dx[i];
            
            if(uy < 0 || uy >= y || ux < 0 || ux >= x || maps[uy][ux]=='X')
                continue;
                
            if(!visited[uy][ux]){
                visited[uy][ux] = true;
                q.push({{uy, ux}, counter+1});
            }
        }
    }
    if(answer==987654321)
        return;

    bfs2(exitY, exitX, maps, answer);
}

int solution(vector<string> maps) {
    int answer = 987654321;
    y = maps.size();
    x = maps[0].size();
    
    for(int i = 0;i<y; i++){
        for(int j = 0;j<x;j++){
            if(maps[i][j]=='S')
                bfs1(i, j, maps, answer);
        }
    }
    if(answer == 987654321) 
        return -1;
    return answer;
}