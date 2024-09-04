#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
bool visited[9];
int arr[9];

void dfs(int x){
    if(x == M){
        for(int i = 0;i<M;i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i = 1;i<=N;i++){
        if(!visited[i]){
            visited[i] = true;
            arr[x] = i;
            dfs(x + 1);
            visited[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;

    dfs(0);
}   