#include <iostream>
#include <queue>
#include <cstring> 
using namespace std;

char graph[100][100];
int visited[100][100] = { 0, };
int count1 = 0, count2 = 0, N;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1, -1, 0 ,0 };
void dfs(int x, int y) {
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int ux = x + dx[i], uy = y + dy[i];
            if (ux < 0 || uy < 0 || ux >= N || uy >= N) continue;

            if (!visited[ux][uy] && graph[x][y] == graph[ux][uy]) {
                dfs(ux, uy);
            }
        }
   }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                count1++;
            }
        }
    }

    memset(visited, 0, sizeof(visited)); 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] == 'G')
                graph[i][j] = 'R';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
                count2++;
            }
        }
    }

    cout << count1 << ' ' << count2 << '\n';
}