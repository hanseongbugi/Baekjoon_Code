#include <iostream>
#include <queue>
using namespace std;

queue<pair<long,int>> q;
long A, B;
int counter = 0;

void bfs() {
	q.push(make_pair(A,1));
	while (!q.empty()) {
		long now = q.front().first;
		int c = q.front().second;
		q.pop();
		if (now == B) {
			counter = c;
			return;
		}
		if (now > B) continue;

		long calc1 = now * 2;
		long calc2 = now * 10 + 1;
		q.push(make_pair(calc1,c+1));
		q.push(make_pair(calc2, c + 1));

	}
	counter = -1;
}

int main() {
	cin >> A >> B;

	bfs();
	cout << counter << '\n';
}