#include <string>
#include <vector>
#include <queue>
using namespace std;
bool visited[200][200];

void dfs(int y, int x, vector<vector<int>> computers){
    queue<pair<int,int>> q;
    q.push({y,x});
    visited[y][x] = true;
    while(!q.empty()){
        int qy = q.front().first;
        int qx = q.front().second;
        q.pop();
        
        for(int i = 0;i<computers[qx].size();i++){
            if(computers[qx][i] == 1 && !visited[qx][i]){
                q.push({qx,i});
                visited[qx][i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0;i<computers.size();i++){
        for(int j = 0;j<computers[i].size();j++){
            if(computers[i][j] == 1 && !visited[i][j]){
                dfs(i,j, computers);
                answer++;
            }
        }
    }
    return answer;
}