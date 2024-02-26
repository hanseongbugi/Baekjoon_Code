#include<iostream>

using namespace std;

int N, K;
int arr[1000001];
int result = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int start=0, end=0;
	int counter = (arr[start] & 1) ? 1 : 0;
	
	while (true) {
		while (end < N - 1) {
			if (arr[end + 1] & 1) {
				if (counter < K)counter++;
				else break;
			}
			end++;
		}

		if (start > N || end > N)break;
		result = max(result, end - start + 1 - counter);

		if (arr[start] & 1)counter--;
		start++;
	}
	cout << result << '\n';
	return 0;
}