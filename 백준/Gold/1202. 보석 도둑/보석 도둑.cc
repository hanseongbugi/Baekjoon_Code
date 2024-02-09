#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int N, K;
long long value = 0;
priority_queue <int, vector<int>>q;
vector<int> bag;
vector<pair<int, int>> jewerly;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	int M, V;
	for (int i = 0; i < N; i++) {
		cin >> M >> V;
		jewerly.push_back({ M,V });
	}
	int C;
	for (int i = 0; i < K; i++) {
		cin >> C;
		bag.push_back(C);
	}
	sort(jewerly.begin(), jewerly.end());
	sort(bag.begin(), bag.end());
	int index = 0;
	for (int i = 0; i < bag.size(); i++) {
		while (index < N && bag[i] >= jewerly[index].first) {
			q.push(jewerly[index].second);
			index++;
		}
		if (!q.empty()) {
			value += q.top();
			q.pop();
		}
	}
	cout << value<<'\n';
}