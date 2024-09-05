#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int S[21][21];
bool visited[21];
int answer = 987654321;

// 0 1 2 3

// 0 1
// 2 3

// 0 2
// 1 3
void dfs(int idx, int cnt){
    if(cnt == N/2){
        int start = 0, link = 0;
        for(int i = 0;i<N;i++){
            for(int j = 0;j<N;j++){
                if(visited[i] && visited[j]){
                    start += S[i][j];
                }
                else if(!visited[i] && !visited[j]){
                    link += S[i][j];
                }
            }
        }
        answer = min(answer,abs(start - link));
        return;
    }
    for(int i = idx;i<N;i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(i + 1,cnt + 1);
            visited[i] = false;
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
            cin>>S[i][j];
    }

    dfs(0, 0);
    cout<<answer;
}   