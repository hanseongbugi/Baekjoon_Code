#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;

int graph[1001][1001] = {0, };
int N, M, V;
int visited[1001] = {0,};
vector<int> stack;
queue<int> q;

void DFS(){
    stack.push_back(V);
    
    while(!stack.empty()){
        int p = stack.back();
        stack.pop_back();
        
        if(visited[p]) continue;
        
        visited[p] = 1;
        cout<<p<<' ';
        for(int next = N; next >= 1; next--){
        	if(!visited[next] && graph[p][next])
            	stack.push_back(next);
        }
    }
    cout<<'\n';
}

void init(){
    for(int i = 0;i<1001;i++){
        visited[i] = 0;
    }
}

void BFS(){
    q.push(V);

	 while(!q.empty()){
        int p = q.front();
        q.pop();
        
        if(visited[p]) continue;
        
        visited[p] = 1;
        cout<<p<<' ';
        for(int next = 1; next <= N; next++){
        	if(!visited[next] && graph[p][next])
            	q.push(next);
        }
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M>>V;
    for(int i = 0;i<M;i++){
        int p, e;
        cin>>p>>e;
        graph[p][e] = 1;
        graph[e][p] = 1;
    }
    DFS();
    init();
    BFS();
    
}