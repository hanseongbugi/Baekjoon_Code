#include <iostream>
#include <cstring>
using namespace std;

int w, h;
int map[51][51];
bool visited[51][51];
int answer = 0;
int dy[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};

void dfs(int y,int x){

    visited[y][x] = true;
    for(int i = 0;i<8;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || ny >= h || nx < 0 || nx >= w)
            continue;
        
        if(map[ny][nx] == 1 && !visited[ny][nx])
            dfs(ny, nx);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(true){
        cin>>w>>h;
        if(w == 0 && h == 0)
            break;
        
        memset(map,0,sizeof(map));
        memset(visited,false,sizeof(visited));
        answer = 0;

        for(int i = 0;i<h;i++)
            for(int j = 0;j<w;j++)
                cin>>map[i][j];
        
        for(int i = 0;i<h;i++)
            for(int j = 0;j<w;j++){
                if(map[i][j] == 1 && !visited[i][j]){
                    dfs(i,j);
                    answer++;
                }
            }


        cout<<answer<<'\n';
    }
}