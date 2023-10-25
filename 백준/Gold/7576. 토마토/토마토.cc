#include <iostream>
#include <queue>
using namespace std;

int M, N;
int tomato[1001][1001] = {0, };
int visited[1001][1001] = {0, };
int path[1001][1001] = {0, };
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
queue< pair<int,int> > q;
 
void bfs() {
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
 
            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;

            if (tomato[ny][nx] == 0 && !visited[ny][nx]) {
                visited[ny][nx] = 1;
                q.push(make_pair(ny, nx));
                path[ny][nx] = path[y][x] + 1;
            }
        }
    }
 
}
 
int main() {
    cin >> M >> N;
 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tomato[i][j];

			// 익은 토마토가 2개 이상이면 동시에 여러개의 토마토를 익혀야함
			if (tomato[i][j] == 1) {
                q.push(make_pair(i, j)); // 익은 토마토의 위치를 큐에 삽입 
            }
        }
    }

    bfs();
 
    //방문 일자 저장 배열 중 최대값 출력
    int ans = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (path[i][j] > ans) {
                ans = path[i][j];
            }
			// 익지 않은 토마토 존재하면 -1 출력
			if (tomato[i][j] == 0 && path[i][j]==0) { //익지 않은 토마토가 있으나 방문한적 없음
                cout << -1 <<'\n';
                return 0;
            }
        }
    }
    cout << ans<<'\n';
 
}
