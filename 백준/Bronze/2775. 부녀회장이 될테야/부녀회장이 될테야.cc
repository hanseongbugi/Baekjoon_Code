#include <iostream>
using namespace std;

int K,N;
int dp[15][15];



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 1; i <= 14; i++)
		dp[0][i] = i;

	for (int i = 0; i < T; i++) {
		cin >> K;
		cin >> N;
		
		for (int j = 1; j <= K; j++) {
			dp[j][1] = dp[j - 1][1];
			for (int l = 2; l <= N; l++) {
				dp[j][l] = dp[j][l - 1] + dp[j - 1][l];
			}
		}
		cout << dp[K][N] << '\n';
	}
		
}