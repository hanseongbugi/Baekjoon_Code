#include <string>
#include <vector>
#include <queue>

using namespace std;
pair<int, int> start;
pair<int, int> goal;
int y, x, answer = 987654321;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
bool visited[100][100];

void bfs(vector<string> &board) {
    queue<pair<pair<int, int>, int>> q;
    
    q.push({{start.first, start.second}, 0});
    visited[start.first][start.second] = true;
    
    while (!q.empty()) {
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        
        if (cy == goal.first && cx == goal.second) {
            answer = min(answer, cnt);
        }
        
        for (int i=0; i<4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if ((ny < 0 || y <= ny || nx < 0 || x <= nx) || board[ny][nx] == 'D') continue;
            
            while (true) {
                ny += dy[i];
                nx += dx[i];
                
                if ((ny < 0 || y <= ny || nx < 0 || x <= nx) || board[ny][nx] == 'D') {
                    ny -= dy[i];
                    nx -= dx[i];
                    break;
                }
            }
           
            if (visited[ny][nx]) continue;
            
            q.push({{ny, nx}, cnt + 1});
            visited[ny][nx] = true;
        }
    }
}

int solution(vector<string> board) {
    answer = 987654321;
    
    y = board.size();
    x = board[0].size();
    
    int counter = 0;
    for(int i = 0;i<y;i++){
        for(int j = 0;j<x;j++){
            if(counter == 2) break;
            
            if(board[i][j] == 'R'){
                counter++;
                start = {i, j};
            }
            else if(board[i][j] == 'G'){
                counter++;
                goal = {i,j};
            }
        }
    }
    bfs(board);
    if(answer == 987654321)
        return -1;
    
    return answer;
}