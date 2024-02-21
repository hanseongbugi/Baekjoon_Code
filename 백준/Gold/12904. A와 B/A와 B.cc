#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

string S, T;
int result = 0;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> S;
	cin >> T;
	
	while (S.length() != T.length()) {
		if (T[T.length() - 1] == 'B') {
			T.pop_back();
			reverse(T.begin(), T.end());
		}
		else {
			T.pop_back();
		}
	}
	if (S == T) result = 1;

	
	cout << result << '\n';
}