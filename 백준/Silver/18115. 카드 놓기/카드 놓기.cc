#include <iostream>
#include <deque>
#include<vector>
using namespace std;

int N;
deque<int> dq;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);

	cin >> N;
	int input;
	for (int i = 0; i < N; i++) {
		cin >> input;
		v.push_back(input);
	}
	int card = 1;
	for (int i = N - 1; i>=0; i--) {
		int calc = v[i];
		if (calc == 1) {
			dq.push_back(card);
		}
		if (calc == 2) {
			int temp = dq.back();
			dq.pop_back();
			dq.push_back(card);
			dq.push_back(temp);
		}
		if (calc == 3) {
			dq.push_front(card);
		}
		card++;
	}

	while (!dq.empty()) {
		int val = dq.back();
		dq.pop_back();
		cout << val << ' ';
	}
	cout << '\n';
	
}