#include <iostream>
#include <vector>
using namespace std;

int N, K;
int arr[11];
int index = 0, value = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);

	cin >> N >> K;
	int coin;
	for (int i = 0; i < N; i++) {
		cin >> coin;
		if (coin <= K) 
			arr[index++] = coin;
	}	
	int last = K;
	for (int i = index - 1; i >=0; i--) {
		value += last / arr[i];

		last %= arr[i];
		if (last <= 0) break;
	}

	cout << value << '\n';
}