#include <iostream>
#include <string>
using namespace std;

int N;
long long dp[101];

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		dp[1] = 1;
		dp[2] = 1;
		dp[3] = 1;
		dp[4] = 2;
		dp[5] = 2;
		for (int i = 6; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 5];
		}

		cout << dp[N] << '\n';
	}
}