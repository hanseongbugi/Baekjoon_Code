#include <iostream>
using namespace std;

int N;
int dp[5001];

int main() {
	cin >> N;
	// 15 , 12, 9, 6, 3, 0
	// 13, 8, 3
	//     18
	//    15 13
	//   12 10 8
	//  9  7  5  3
	// 6 4  2   0  -2
	//      6
	//     3 1
	//    0 -2 -4

	//      4
	//     1  -1
	//   -2 -4  -6
	dp[3] = 1;
	dp[5] = 1;

	for (int i = 6; i <= N; i++) {
		if (dp[i - 3]) 
			dp[i] = dp[i - 3] + 1;

		if (dp[i - 5]) 
			dp[i] = dp[i] ? min(dp[i], dp[i - 5] + 1) : dp[i - 5] + 1;
	}
	cout << (dp[N] == 0 ? -1 : dp[N]) << '\n';
}