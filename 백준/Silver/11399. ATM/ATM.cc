#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int dp[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int value;
		cin >> value;
		v.push_back(value);
	}
	sort(v.begin(), v.end());
	dp[0] = v[0];
	int result = dp[0];
	for (int i = 1; i < N; i++) {
		dp[i] = v[i] + dp[i - 1];
		result += dp[i];
	}
	cout << result << '\n';
}