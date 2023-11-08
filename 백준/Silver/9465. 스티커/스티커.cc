#include <iostream>
#include<cstring>
using namespace std;
int T, N, result = 0;
int arr[2][100001] = { 0, };
int dp[2][100001] = { 0, };


int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		result = 0;
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		cin >> N;
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < N; k++) {
				cin >> arr[j][k];
			}
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		
		dp[0][1] = dp[1][0] + arr[0][1];
		dp[1][1] = dp[0][0] + arr[1][1];
		result = max(max(dp[0][0], dp[1][0]), max(dp[0][1], dp[1][1]));

		for (int j = 2; j < N; j++) {
			dp[0][j] = max(dp[1][j - 2] + arr[0][j], max(dp[1][j - 1] + arr[0][j], dp[0][j - 2] + arr[0][j]));
			dp[1][j] = max(dp[0][j - 2] + arr[1][j], max(dp[0][j - 1] + arr[1][j], dp[1][j - 2] + arr[1][j]));
			result = max(result, max(dp[0][j], dp[1][j]));
		}
		cout << result << '\n';
	}
}