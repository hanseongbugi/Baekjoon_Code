#include <iostream>
#include <vector>
using namespace std;

int N, M;
int room[51][51];
int r, c, d; // 0 : 북, 1 : 동, 2 : 남, 3 : 서
int dy[4] = {-1, 0, 1, 0}; // 북, 서, 남, 동
int dx[4] = {0, 1, 0, -1};
int answer = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>M; // 방 크기

    cin>>r>>c>>d; // 처음 좌표, 방향

    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++)
            cin>>room[i][j]; // 방 상태
    }

    while(room[r][c] != 1){
        if(room[r][c] == 0){
            room[r][c] = 2;
            answer++;
        }
        bool isClear = false;
        for(int i = 0;i<4;i++){
            d--;
            if(d < 0)
                d = 3;
            int ny = r + dy[d];
            int nx = c + dx[d];
            if(ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            
            if(room[ny][nx] == 0){
                r = ny;
                c = nx;
                isClear = true;
                break;
            }
        }
        if(!isClear){
            r -= dy[d];
            c -= dx[d];
        }
    }
    cout<<answer;
}