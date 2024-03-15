#include<iostream>
using namespace std;
 
int N, K;
long long sum, dp[100001], temp, ans;
int arr[100001];
 
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
 
	cin >> N >> K;

	for (int i = 0;i<N;i++) 
        cin >> arr[i];

    int start = 0, end = 0;

	while (end <= N) {
		if (sum >= K) {
			temp = (start == 0 ? 0 : max(temp, dp[start - 1]));
			dp[end - 1] = max(dp[end - 1], temp + sum - K);
			sum -= arr[start++];
		}
		else sum += arr[end++];
	}

	for (int i = 0; i < N; i++)
		ans = max(ans, dp[i]);

	cout << ans<<'\n';
}