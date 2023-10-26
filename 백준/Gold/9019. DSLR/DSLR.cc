#include <queue>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int A, B;
int visited[10000] = {0, };

void bfs()
{
    queue< pair<int, string> > q;
    q.push(make_pair(A, ""));
    visited[A] = 1;

    while (!q.empty())
    {
        int now = q.front().first;
        string path = q.front().second;
        q.pop();

        if (now == B)
        {
            cout << path << '\n';
            return;
        }

        int D, S, L, R, temp;
        // D 연산
        D = (now * 2) % 10000;
        if (!visited[D])
        {
            visited[D] = 1;
            q.push(make_pair(D, path + "D"));
        }

        // S 연산
        S = now - 1 < 0 ? 9999 : now - 1;
        if (!visited[S])
        {
            visited[S] = 1;
            q.push(make_pair(S, path + "S"));
        }

        // L 연산
        L = (now % 1000) * 10 + (now / 1000);
        if (!visited[L])
        {
            visited[L] = true;
            q.push(make_pair(L, path + "L"));
        }

        // R 연산
        R = now / 10 + (now % 10) * 1000;
        if (!visited[R])
        {
            visited[R] = 1;
            q.push(make_pair(R, path + "R"));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        cin >> A >> B;
        memset(visited, 0, sizeof(visited)); // 초기화
        bfs();
    }

    return 0;
}