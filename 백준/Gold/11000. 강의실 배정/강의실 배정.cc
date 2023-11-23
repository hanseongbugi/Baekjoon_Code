#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N;
int main() {
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> q;
	vector<pair<int,int>> v;
	for (int i = 0; i < N; i++) {
		int S, T;
		cin >> S >> T;
		v.push_back(make_pair(S, T));
	}
	// 1 3 3 5, 2 4, 6 7
	// 1 3 3 5  2 4 6 7
	// 13 3 5 6 7, 2 4

	sort(v.begin(), v.end());

	q.push(v[0].second);
	for (int i = 1; i < N; i++) {
		q.push(v[i].second);
		if (q.top() <= v[i].first) {
			q.pop();
		}
	}
	cout << q.size() << '\n';
}