#include <iostream>
#include <queue>
using namespace std;

int N, K;
int minTime = 987654321;
int answer = 0;
bool visited[100001];
int dir[3] = {-1, 1, 0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>K;
    queue<pair<int,int>> q;
    q.push({N,0});
    while(!q.empty()){
        int now = q.front().first;
        int time = q.front().second;
        q.pop();
        visited[now] = true;

        if(now == K){
            if(minTime > time){
                minTime = time;
                answer = 1;
            }
            else if(minTime == time)
                answer++;
        }


        for(int i = 0;i<3;i++){
            int next;
            if(dir[i] == 0)
                next = now * 2;
            else
                next = now + dir[i];
            
            if(next > 100000 || next < 0)
                continue;

            if(!visited[next]){
                q.push({next, time + 1});
            }
            
        }
    }
    cout<<minTime<<'\n'<<answer;
}   