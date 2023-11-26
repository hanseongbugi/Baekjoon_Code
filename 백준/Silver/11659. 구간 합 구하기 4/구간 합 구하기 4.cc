#include <iostream>

using namespace std;

int N, M;
int arr[100001];
int dp[100001];
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	dp[2] = arr[2] + dp[1];
	for (int i = 3; i <= N; i++)
		dp[i] = arr[i] + dp[i-1];

	for (int k = 0; k < M; k++) {
		int i, j;
		cin >> i >> j;
		cout << dp[j] - dp[i - 1] << '\n';
	}
}
