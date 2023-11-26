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
	vector<pair<int,int>> v;
	int s, e;
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		v.push_back(make_pair(e,s));
	}
	sort(v.begin(), v.end());

	int time = v[0].first;
	int result = 1;
	for (int i = 1; i < N; i++) {
		if (time <= v[i].second) {
			result++;
			time = v[i].first;
		}
	}
	cout << result << '\n';
}