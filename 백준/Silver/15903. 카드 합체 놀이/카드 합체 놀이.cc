#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int main() {
	cin >> N >> M;
	priority_queue<long long, vector<long long>, greater<long long>> cards;

	for (int i = 0; i < N; i++) {
		int card;
		cin >> card;
		cards.push(card);
	}
	// 4 2 3 1
	// 4 3 3 3
	// 4 3 6 6
	// 1000000 1000000 1000000
	// 2000000 2000000 1000000
	// 2000000 3000000 3000000
	// 5000000 5000000 3000000
	// 5000000 8000000 8000000
	for (int i = 0; i < M; i++) {
		long long c1 = cards.top();
		cards.pop();
		long long c2 = cards.top();
		cards.pop();
		cards.push(c1 + c2);
		cards.push(c1 + c2);
	}

	long long value = 0;
	for (int i = 0; i < N; i++) {
		value += cards.top();
		cards.pop();
	}
	cout << value << '\n';
}