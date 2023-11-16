#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int dp[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	cin >> dp[1];
	for (int i = 2; i <= n; i++) {
		cin >> dp[i];
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], dp[j] + dp[i - j]);
		}
	}
	cout << dp[n];
}