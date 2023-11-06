#include <iostream>
using namespace std;

int N,M;
int arr[9] = {0,};
int visited[9] = {0,};

void dfs(int num, int cnt)
{
    if(cnt == M)
    {
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = num; i <= N; i++)
    {
        if(!visited[i])
        {
            visited[i] = 1;
            arr[cnt] = i;
            dfs(i+1,cnt+1);
            visited[i] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    dfs(1,0);
}