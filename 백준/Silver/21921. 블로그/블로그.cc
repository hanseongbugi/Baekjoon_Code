#include<iostream>

using namespace std;

int N, X;
int arr[250001];
int result = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> X;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int start = 0, end = 0;
	int counter = 0;
	int calc = arr[end];
	result = arr[end];
	
	while (start < N) {
		int person = 0;
		start++;
		
		if (start - end >= X) {
			calc -= arr[end];
			end++;
		}
		
		calc += arr[start];
		if (calc > result) {
			counter = 1;
			result = calc;
		}
		else {
			if(calc==result)
				counter += 1;
		}
	}
	if (result == 0)cout << "SAD" << '\n';
	else {
		cout << result << '\n';
		cout << counter << '\n';
		
	}
	return 0;
}