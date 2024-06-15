#include<vector>
#include <queue>
using namespace std;

bool visited[101][101] = {false, };
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int result = 987654321;

void bfs(vector<vector<int>> maps){
    queue<pair<pair<int,int>,int>>q;
    q.push({{0,0},1});
    visited[0][0] = true;
    while(!q.empty()){
        int qy = q.front().first.first;
        int qx = q.front().first.second;
        int counter = q.front().second;
        q.pop();
        if(qy == maps.size() - 1&&qx == maps[0].size() - 1){
            result = min(result,counter);
        }
        for(int i = 0;i<4;i++){
            int uy = qy + dy[i];
            int ux = qx + dx[i];
            
            if(uy < 0 || uy >= maps.size() || ux < 0 || ux >= maps[0].size())
                continue;
            if(maps[uy][ux] == 0)
                continue;
            if(!visited[uy][ux]){
                q.push({{uy,ux},counter + 1});
                visited[uy][ux] = true;
            }
        }
    }
}
int solution(vector<vector<int> > maps)
{
    int answer = 0;
    bfs(maps);
    
    answer = result;
    if(answer == 987654321)
        answer = -1;
    
    return answer;
}