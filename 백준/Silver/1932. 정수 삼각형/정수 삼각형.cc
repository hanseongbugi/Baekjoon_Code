#include <iostream>
using namespace std;
int N;
int arr[501][501];
int dp[501][501];


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	dp[0][0] = arr[0][0];
	dp[1][0] = dp[0][0] + arr[1][0];
	dp[1][1] = dp[0][0] + arr[1][1];


	for (int i = 2; i < N; i++) {
		for (int j = 0; j < i; j+=1) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j]);
			dp[i][j + 1] = max(dp[i][j + 1], dp[i - 1][j] + arr[i][j + 1]);
		}
	}
	int result = 0;
	for (int i = 0; i < N; i++)
		result = max(result, dp[N - 1][i]);

	cout << result << '\n';
}