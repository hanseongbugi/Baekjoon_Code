#include <iostream>
#include <cmath>
using namespace std;

int N, result;
int dp[10001] = { 0, };
int cups[10001] = { 0, };

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		cin >> cups[i];
	}

	dp[0] = cups[0]; // 첫번째 컵 선택
	dp[1] = max(dp[0] + cups[1], cups[1]); // 첫번째 컵과 두번째 컵 혹은 두번째 컵
	dp[2] = max(max(cups[0] + cups[1], cups[0] + cups[2]), cups[1] + cups[2]);
	// dp [2] = 0,1 0,2 1,2
	for (int i = 3; i < N; i++) {
		dp[i] = max(max(dp[i - 3] + cups[i - 1] + cups[i], dp[i - 2] + cups[i]), dp[i-1]);
	}
	cout << dp[N - 1] << '\n';
}