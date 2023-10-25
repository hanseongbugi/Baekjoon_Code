#include <iostream>
#include <queue>
using namespace std;

queue< pair<int,int> > q;
int visited[100001] = {0, };
int N, K, counter = 0;

void bfs(){
	q.push(pair<int,int>(N,0));
	visited[N] = 1;
	while(!q.empty()){
		int now = q.front().first;
		int time = q.front().second;
		q.pop();

		if(now == K){
			cout<<time<<'\n';
			return;
		}
		time += 1;
		for(int i = -1; i<2; i++){
			int index = now + i;
			if(i == 0){
				index = now * 2;
			}
            if(index >= 100001) continue;
			if(!visited[index]){
				q.push(pair<int,int>(index, time));
				visited[index] = 1;
			}
		}

	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin>>N>>K;
	bfs();
}