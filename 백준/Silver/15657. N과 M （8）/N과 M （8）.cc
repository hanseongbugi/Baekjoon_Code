#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
int arr[9] = { 0, };
vector<int> graph;

void dfs(int num,int cnt)
{
    if (cnt == M)
    {
        for (int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = num; i < N; i++)
    {

         arr[cnt] = graph[i];
         dfs(i,cnt + 1);

    }
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int value;
        cin >> value;
        graph.push_back(value);
    }
    sort(graph.begin(), graph.end());
    dfs(0, 0);
}