#include<iostream>
#include<string>
using namespace std;

int H, W, N;
pair<pair<int, int>, int> sticker[200];
bool visited[100];
pair<int, int> selected[2];
int result = 0;

void check() {
	
	if (selected[0].second + selected[1].second <= W) {
		if (max(selected[0].first, selected[1].first) <= H) {
			result = max(result, selected[0].first * selected[0].second + selected[1].first * selected[1].second);
		}
	}
	if (selected[0].second + selected[1].second <= H) {
		if (max(selected[0].first, selected[1].first) <= W) {
			result = max(result, selected[0].first * selected[0].second + selected[1].first * selected[1].second);
		}
	}
	
}
void combination(int idx, int size, int counter) {
	if (counter == 2) {
		check();
		return;
	}
	for (int i = idx; i < size; i++) {
		int r = sticker[i].first.first;
		int c = sticker[i].first.second;
		int target = sticker[i].second;

		if (visited[target]) continue; // 스티커 중복 선택 방지
		visited[target] = true;
		selected[counter] = { r,c };

		combination(idx + 1, size, counter + 1);
		selected[counter] = { 0,0 };
		visited[target] = false;
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> H>>W;
	cin >> N;

	int idx = 0;
	for (int i = 0; i < N; i++) {
		int R, C;
		cin >> R >> C;
		sticker[idx++] = { {R,C},i };
		if (R != C) {
			sticker[idx++] = { {C,R},i };
		}
	}
	combination(0, idx, 0);
	cout << result << '\n';
	return 0;
}