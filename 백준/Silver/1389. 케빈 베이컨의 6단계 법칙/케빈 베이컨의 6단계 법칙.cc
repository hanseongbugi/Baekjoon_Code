#include <iostream>
#include <queue>
using namespace std;

queue<pair<int,int> > q;
int graph[100][100] = {0, };
int visited[100] = {0, };
int N, M, counter = 5001, person;

void init(){
	for(int i = 1; i<=N;i++){
		visited[i] = 0;
	}
}

void bfs(int start){
	int kabin = 0;
	q.push(pair<int, int>(start, 0));
	visited[start] = 1;

	while(!q.empty()){
		int now = q.front().first;
		int num = q.front().second;
		num += 1;
		q.pop();
		for(int next = 1; next <= N; next++){
			if(!visited[next] && graph[now][next]){
				q.push(pair<int,int>(next,num));
				visited[next] = 1;
				kabin += num;
			}
		}
	}
	if(counter>kabin){
		person = start;
		counter = kabin;
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin>>N>>M;
	
	for(int i = 0;i<M;i++){
		int u, f; 
		cin>>u>>f;
		graph[u][f] = 1; graph[f][u] = 1;
	}
	for(int i = 1; i<=N; i++){
		init();
		bfs(i);
	}
	cout<<person<<'\n';
}