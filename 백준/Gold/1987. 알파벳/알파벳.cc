#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int R, C;
char alpha[21][21];
bool visited[26];
int answer = 0;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void dfs(int y, int x, int cnt){
    answer = max(answer, cnt);
    for(int i = 0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= R || nx < 0 || nx >= C)
            continue;
        
        if(visited[alpha[ny][nx] - 'A'])
            continue;
        visited[alpha[ny][nx] - 'A'] = true;
        dfs(ny, nx, cnt + 1);
        visited[alpha[ny][nx] - 'A'] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>R>>C;
    for(int i = 0;i<R;i++){
        for(int j = 0;j<C;j++)
            cin>>alpha[i][j];
    }
    
    visited[alpha[0][0] - 'A'] = true;
    dfs(0,0, 1);

    cout<<answer;
}   