#include <iostream>
using namespace std;
int K;
int dp[46][2];

int main() {
	cin >> K;
	dp[0][0] = 1;
	dp[0][1] = 0;
	dp[1][0] = 0;
	dp[1][1] = 1;
	for (int i = 2; i <= K; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}

	cout << dp[K][0] << " " << dp[K][1] << '\n';

}