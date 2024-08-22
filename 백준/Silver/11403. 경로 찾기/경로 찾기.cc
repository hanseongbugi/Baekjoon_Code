#include <iostream>
#include <cstring>
using namespace std;

int N;
int graph[101][101];
bool visited[101][101];
int answer[101];

void dfs(int now){
    for(int i = 0;i<N;i++){
        if(graph[now][i] == 1 && !visited[now][i]){
            visited[now][i] = 1;
            dfs(i);
            answer[i] = 1;
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin>>N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++)
            cin>> graph[i][j];
    }
    for(int i = 0;i<N;i++){
        memset(visited, false, sizeof(visited));
        memset(answer, 0, sizeof(answer));
        dfs(i);
        for(int j = 0;j<N;j++)
            cout<<answer[j]<<' ';
        cout<<'\n';
    }
}