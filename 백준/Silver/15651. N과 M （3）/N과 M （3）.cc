#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
bool visited[8];
int arr[8];

void dfs(int x){
    if(x == M){
        for(int i = 0;i<M;i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }

    for(int i = 1;i<=N;i++){
        arr[x] = i;
        dfs(x + 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;

    dfs(0);
}   