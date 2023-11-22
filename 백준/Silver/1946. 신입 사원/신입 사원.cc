#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int main() {
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		vector<pair<int, int>> v;
		cin >> N;
		for (int j = 0; j < N; j++) {
			int t1, t2;
			cin >> t1 >> t2;
			v.push_back(make_pair(t1, t2));
		}
		sort(v.begin(), v.end());

		int result = 1;
		int n = v[0].second;
		for (int j = 1; j < v.size(); j++) {
			if (n > v[j].second) {
				n = v[j].second;
				result += 1;
			}
		}

		cout << result << '\n';


	}

	
}