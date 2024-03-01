#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int T;
int result = -1;

// 비트 마스크 = { 000 000 111, 000 111 000, 111 000 000, 001 001 001, 010 010 010,
// 100 100 100, 100 010 001, 001 010 100 }
int mask[] = { 7,56,448,73,146,292,273,84 };
bool visited[512] = { false };

int makeBit(string s) {
	int bit = 0;
	for (int i = 8; i >= 0; i--) {
		bit <<= 1;
		if (s[i] == 'H') bit |= 1;
	}
	return bit;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int i = 0; i < T; i++) {
		string coin;
		char c;
		memset(visited, false, sizeof(visited));
		result = -1;

		for (int j = 0; j < 9; j++) {
			cin >> c;
			coin += c;
		}
		
		int bit = makeBit(coin);
		queue<int> q;
		q.push(bit);
		visited[bit] = true;

		bool sucess = false;

		while (!q.empty() && !sucess) {
			result++;
			int n = q.size();
			while (n--) {
				int current = q.front();
				q.pop();
				if (current == 0 || current == (1 << 9) - 1) {
					sucess = true;
					break;
				}
				for (int j = 0; j < 8; j++) {
					int nextState = current ^ mask[j];
					if (visited[nextState]) continue;
					visited[nextState] = true;
					q.push(nextState);
				}
			}
		}
		if (sucess) cout << result << '\n';
		else cout << -1 << '\n';
	}
	return 0;
}