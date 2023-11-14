#include <iostream>
#include <cmath>
using namespace std;

int N, maxNum;
int dp[100001];
int arr[100001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	dp[0] = arr[0];
	maxNum = arr[0];
	
	for (int i = 1; i < N; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		maxNum = max(dp[i], maxNum);
	}
	cout << maxNum << '\n';
}