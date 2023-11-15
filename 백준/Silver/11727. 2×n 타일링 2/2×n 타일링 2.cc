#include <iostream>
#include <cmath>
using namespace std;

int N;
int dp[1001] = { 0, };

int main() {
	cin >> N;
	
	dp[1] = 1; // 1
	dp[2] = 3; // 2
	dp[3] = 5; // 3 
	dp[4] = 11; // 3 * 2 + 5
	dp[5] = 21; // 5 * 2 + 11
	// dp[6] = // 11 * 2 + 21
	// dp[7] = // 21 * 2 + 43
	// dp[8] = // 43 * 2 + 85 = 171
	for (int i = 6; i <= N; i++) {
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
	}
	cout << dp[N] << '\n';
}