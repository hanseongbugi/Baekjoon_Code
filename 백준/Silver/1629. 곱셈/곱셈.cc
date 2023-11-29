#include <iostream>
using namespace std;
long long A, B, C;

long long divide(long long a, long long b, long long c) {
	if (b == 1) return a % c;

	long long calc = divide(a, b / 2, c) % c;
	if (b % 2 == 0) return calc * calc % c;
	else
		return calc * calc % c * a % c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	

	cin >> A >> B >> C;

	cout << divide(A, B, C)<<'\n';
}