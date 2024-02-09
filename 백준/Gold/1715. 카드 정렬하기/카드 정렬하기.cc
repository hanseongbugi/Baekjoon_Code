#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N;
int value = 0;
priority_queue<int, vector<int>, greater<int>> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		q.push(input);
	}
	
	while (q.size() > 1) {
		int n1 = q.top();
		q.pop();
		int n2 = q.top();
		q.pop();
		value += n1 + n2;
		q.push(n1+n2);
	}
	cout << value << '\n';
}