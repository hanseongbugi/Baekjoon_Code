#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
pair<int, int> foods[11];
pair<int, int> box[11];
int result = 987654321;

void combination(int index, int counter) {
	if (counter > 0) {
		int S = box[0].first;
		int B = box[0].second;
		for (int i = 1; i < counter; i++) {
			S *= box[i].first;
			B += box[i].second;
		}
		result = min(result, abs(S - B));
	}
	if (counter == N) return;
	for (int i = index; i < N; i++) {
		box[counter] = { foods[i].first, foods[i].second };
		combination(i + 1, counter + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) 
		cin >> foods[i].first >> foods[i].second;
	

	combination(0, 0);

	cout << result << '\n';
	return 0;
}