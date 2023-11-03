#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int T, N;
int check[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		priority_queue<pair<int, int>> max_q;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_q;
		for (int i = 0; i < N; i++) {
			char order;
			int num;
			cin >> order >> num;
			if (order == 'I') {
				max_q.push(make_pair(num, i));
				min_q.push(make_pair(num, i));
				check[i] = 1;
			}
			else if (order == 'D') {
				if (num == -1) {
					while (!min_q.empty()) {
						int X = min_q.top().second;
						if (check[X] == 1) break;
						min_q.pop();
					}
					if (min_q.size() > 0) {
						int X = min_q.top().second;
						check[X] = 0;
					}
				}
				else {
					while (!max_q.empty()) {
						int X = max_q.top().second;
						if (check[X] == 1) break;
						max_q.pop();
					}
					if (max_q.size() > 0) {
						int X = max_q.top().second;
						check[X] = 0;
					}
				}
			}
		}
		while (!min_q.empty()) {
			int X = min_q.top().second;
			if (check[X] == 1) break;
			min_q.pop();
		}
		while (!max_q.empty()) {
			int X = max_q.top().second;
			if (check[X] == 1) break;
			max_q.pop();
		}
		if (max_q.empty() && min_q.empty()) cout << "EMPTY" << "\n";
		else cout << max_q.top().first << " " << min_q.top().first << "\n";
	}
	return 0;
}