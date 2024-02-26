#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int N;
string input;
int isPalindrome(int left, int right, bool reTest) {
	while (left < right) {
		if (input[left] != input[right]) {
			if (reTest) {
				if (isPalindrome(left + 1, right, false) == 0 || isPalindrome(left, right - 1, false) == 0)return 1;
			}
			return 2;
		}
		left++;
		right--;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> input;
		cout << isPalindrome(0, input.size() - 1, true)<<'\n';
	}
	return 0;
}