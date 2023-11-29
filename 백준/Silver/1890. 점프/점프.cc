#include <iostream>
using namespace std;

int N;
int graph[101][101] = { 0, };
long long dp[101][101];



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	dp[0][0] = 1;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int jump = graph[i][j];
			if (jump == 0)break;

			if (i + jump < N) dp[i + jump][j] += dp[i][j];
			if (j + jump < N)dp[i][j + jump] += dp[i][j];
		}
	}

	cout << dp[N-1][N-1] << '\n';
}