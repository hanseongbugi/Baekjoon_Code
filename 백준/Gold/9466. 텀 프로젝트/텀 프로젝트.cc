#include <iostream>
#include <cstring>
using namespace std;

int T;
int n;
int graph[100001];
int answer = 0;
bool visited[100001];
bool done[100001];


void isCycle(int r){
    visited[r] = true;
    int next = graph[r];

    if(!visited[next])
        isCycle(next);
    else if(!done[next]){
        // 방문 했지만 아직 사이클이 아닌 경우
        // 자기 자신을 포함한 멤버들을 카운트
        int i = next;
        while(i != r){
            answer++;
            i = graph[i];
        }
        answer++;
    }
    done[r] = true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    
    cin>>T;
    while(T--){
        cin>>n;
        int to;
        for(int i = 1;i<=n;i++){
            cin>>to;
            graph[i] = to;
        }
        answer = 0;
        memset(visited,false,sizeof(visited));
        memset(done, false, sizeof(done));

        for(int i = 1;i<=n;i++){
            if(!visited[i])
                isCycle(i);
        }

        cout<<n - answer<<'\n';
    }
}   