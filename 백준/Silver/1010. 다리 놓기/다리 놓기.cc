#include <iostream>
using namespace std;
int N, M;
int result;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		int calc = 1;
		result = 1;
		for (int i = M; i > M - N; i--) {
			result = result * i;
			result = result / calc++;
		}
		cout << result << '\n';
	}
	
	
}