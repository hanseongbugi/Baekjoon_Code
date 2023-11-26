#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	priority_queue<int, vector<int>, greater<int>> heap;

	int value;
	for (int i = 0; i < N; i++) {
		cin >> value;
		if (value == 0) {
			if (heap.empty()) cout << 0 << '\n';
			else {
				cout << heap.top() << '\n';
				heap.pop();
			}
		}
		else {
			heap.push(value);
		}
	}
}