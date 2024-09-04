#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M;
int graph[101][101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    int go, to, cost;

    for(int i = 0;i<=N;i++){
        for(int j = 0;j<=N;j++){
            if(i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = 987654321;
        }
    }
    for(int i = 0;i<M;i++){
        cin>>go>>to>>cost;
        graph[go][to] = min(graph[go][to], cost);
    }
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            for(int k = 1;k<=N;k++)
                graph[j][k] = min(graph[j][k],graph[j][i] + graph[i][k]);
        }
    }
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=N;j++){
            if(graph[i][j] == 987654321)
                cout<<0<<' ';
            else
                cout<<graph[i][j]<<' ';
        }
        
        cout<<'\n';
    }
}