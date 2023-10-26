#include <iostream>
#include <queue>
using namespace std;

typedef struct Point{
    int x; int y; int z;
}Point;

int M, N, H;
int tomato[100][100][100] = {0, };
int visited[100][100][100] = {0, };
int path[100][100][100] = {0, };
int dz[] = { 1, -1, 0, 0, 0, 0}; // 위, 아래, 왼쪽, 오른쪽, 앞, 뒤
int dy[] = { 0, 0, 1, -1, 0, 0};
int dx[] = { 0, 0, 0, 0, 1, -1 };
queue<Point> q;

void bfs() {
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();
 
        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
 
            if (ny < 0 || nx < 0 || nz < 0 || nx >= N || ny >= M || nz >= H)
                continue;

            if (tomato[nx][ny][nz] == 0 && !visited[nx][ny][nz]) {
                visited[nx][ny][nz] = 1;
                Point p = {nx, ny, nz};
                q.push(p);
                path[nx][ny][nz] = path[x][y][z] + 1;
            }
        }
    }
 
}
 
int main() {
    cin >> M >> N >> H;
    
    for(int k = 0; k< H; k++){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> tomato[i][j][k];

			    // 익은 토마토가 2개 이상이면 동시에 여러개의 토마토를 익혀야함
			    if (tomato[i][j][k] == 1) {
                    Point p = {i, j, k};
                    q.push(p); // 익은 토마토의 위치를 큐에 삽입 
                }
            }
        }
    }

    bfs();
 
    //방문 일자 저장 배열 중 최대값 출력
    int ans = -1;
    for(int k = 0; k< H; k++){
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (path[i][j][k] > ans) {
                    ans = path[i][j][k];
                }
			    // 익지 않은 토마토 존재하면 -1 출력
			    if (tomato[i][j][k] == 0 && path[i][j][k]==0) { //익지 않은 토마토가 있으나 방문한적 없음
                    cout << -1 <<'\n';
                    return 0;
                }
            }
        }
    }
    cout << ans<<'\n';
 
}