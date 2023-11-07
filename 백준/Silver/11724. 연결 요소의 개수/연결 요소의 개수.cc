#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, cnt = 0;
int visited[1001] = { 0, };
int graph[1001][1001] = { 0, };

void dfs(int num)
{
    visited[num] = 1;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]&&graph[num][i]) {
            dfs(i);
        }
    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int go, to;
        cin >> go >> to;
        graph[go][to] = 1; graph[to][go] = 1;
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << '\n';
}