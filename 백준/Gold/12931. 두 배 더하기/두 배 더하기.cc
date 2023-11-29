#include <iostream>
#include<cmath>
using namespace std;

int N;
int B[51] = { 0, };
int calced[1001] = { 0, };
int result = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int big = 0;
	for (int i = 0; i < N; i++) {
		cin >> B[i];
	}


	int result = 0;
	while (1) {
		int zero = 0;
		for (int i = 0; i < N; i++) {
			if (B[i] % 2) {
				result++;
				B[i]--;
			}
			if (B[i] == 0)
				zero++;
		}
		if (zero == N) break;
		result++;
		for (int i = 0; i < N; i++)
			B[i] /= 2;
	}

	cout << result << '\n';
}