#include<iostream>

using namespace std;

int N, K;
int arr[200001];
int element[100001];
int result = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// 0 1 1 2 3 1 1
	int start = 0;
	int end = 0;
	
	while (start < N) {
		if (element[arr[start]] != K) {
			element[arr[start]]++;
			start++;
		}
		else {
			element[arr[end]]--;
			end++;
		}
		result = max(result, start - end);
	}

	cout << result << '\n';
	return 0;
}