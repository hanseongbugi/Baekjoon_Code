#include<iostream>
#include<string>
#include<vector>
using namespace std;

int N;
string T;
int alpha[26] = { 0, };
int target[26] = { 0, };
int result = 1600001;
vector<pair<int, string>> arr;

bool check() {
	for (int i = 0; i < 26; i++) {
		if (alpha[i] > target[i]) {
			return false;
		}
	}
	return true;
}
void combination(int counter, int priceSum) {
	if (counter == N) {
		if (check()) result = min(result, priceSum);
		return;
	}
	for (int i = 0; i < arr[counter].second.length(); i++) {
		target[arr[counter].second[i] - 'A']++;
	}
	combination(counter + 1, priceSum + arr[counter].first);
	for (int i = 0; i < arr[counter].second.length(); i++) {
		target[arr[counter].second[i] - 'A']--;
	}
	combination(counter + 1, priceSum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	cin >> N;

	for (int i = 0; i < T.length(); i++) {
		alpha[T[i] - 'A']++;
	}

	int C;
	string W;
	
	for (int i = 0; i < N; i++) {
		cin >> C >> W;
		arr.push_back({ C,W });
	}
	
	combination(0, 0);

	if (result == 1600001) cout << -1 << '\n';
	else cout << result << '\n';
	return 0;
}