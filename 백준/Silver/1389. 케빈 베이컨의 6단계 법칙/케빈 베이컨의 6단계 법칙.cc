#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int arr[101][101];
bool visited[101];
int answer = 0;
int cavin = 987654321;

int dfs(int target, int goal){
    queue<pair<int,int>> q;
    q.push({target,0});
    visited[target] = true;

    while(!q.empty()){
        int go = q.front().first;
        int num = q.front().second;
        q.pop();
        if(go == goal){
            return num;
        }
        for(int i = 1;i<=N;i++){
            if(arr[go][i] && !visited[i]){
                q.push({i,num + 1});
                visited[i] = true;
            }
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 1 - 3    1 - 3 - 2 
    // 1 - 4      - 4 - 5
    // 2 - 3
    // 3 - 4
    // 4 - 5
    cin>>N>>M;
    int go, to;
    for(int i = 0;i<M;i++){
        cin>>go>>to;
        arr[go][to] = 1;
        arr[to][go] = 1;
    }

    for(int i = 1;i<=N;i++){
        int temp = 0;
        for(int j = 1;j<=N;j++){
            if(j==i)
                continue;
            
            memset(visited,false,sizeof(visited));
            temp += dfs(i,j);
        }
        if(cavin > temp){
            cavin = temp;
            answer = i;
        }
    }

    cout<<answer<<'\n';
}