#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1025; // 최대 배열 크기
int N, M;
int arr[MAXN][MAXN] = {0, };
int dp[MAXN][MAXN] = {0, };

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++)
            cin >> arr[i][j];
    }

    // 누적 합 계산
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        // 부분 합 계산
        int result = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1];
        cout << result << '\n';
    }

    return 0;
}