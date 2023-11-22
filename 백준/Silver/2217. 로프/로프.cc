#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N;
int main() {
	cin >> N;
	vector<int> arr;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	int result = 0;

	for (int i = 0; i < N; i++) {
		result = max(result, arr[i] * (N - i));
	}
	cout << result << '\n';
}