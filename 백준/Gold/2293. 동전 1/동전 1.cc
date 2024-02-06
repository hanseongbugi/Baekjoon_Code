#include <iostream> 

using namespace std;

int N, K;
int dp[10001];
int arr[101];
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dp[0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = arr[i]; j <= K; j++)
			dp[j] += dp[j - arr[i]];
	}
	cout << dp[K] << '\n';
	return 0;
}