#include <iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int x, result;
queue<pair<int,int>> q;

void bfs() {
	q.push(make_pair(x,0));

	while (!q.empty()) {
		int value = q.front().first;
		int counter = q.front().second;
		q.pop();

		if (value == 1) {
			result = counter;
			break;
		}

		if (value % 3 == 0) q.push(make_pair(value/3, counter + 1));

		if (value % 2 == 0) q.push(make_pair(value / 2, counter + 1));

		q.push(make_pair(value - 1, counter + 1));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> x;
	bfs();
	cout << result << '\n';
}