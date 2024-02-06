#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;
int arr[101];
int dp[10001] = { 0, };
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 1; i <= K; i++) dp[i] = 10001; 

	for (int i = 1; i <= N; i++) { 
		for (int j = arr[i-1]; j <= K; j++) { 
			dp[j] = min(dp[j], dp[j - arr[i-1]] + 1);
		}
	}

	if (dp[K] == 10001) cout << -1 << '\n';
	else cout << dp[K] << '\n';
}