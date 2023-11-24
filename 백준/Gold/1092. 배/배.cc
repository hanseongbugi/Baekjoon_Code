#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N, M;

int main() {
	cin >> N;
	vector<int> cont;
	for (int i = 0; i < N; i++) {
		int weight;
		cin >> weight;
		cont.push_back(weight);
	}

	cin >> M;
	vector<int> boxes;
	for (int i = 0; i < M; i++) {
		int weight;
		cin >> weight;
		boxes.push_back(weight);
	}

	sort(cont.begin(), cont.end());
	sort(boxes.begin(), boxes.end());

	if (cont[cont.size() - 1] < boxes[boxes.size() - 1]) {
		cout << -1 << '\n';
		return 0;
	}
	int result = 0;
	while (!boxes.empty()) {
		int index = boxes.size() - 1;
		for (int i = N-1; i >=0; i--) {
			if (boxes.empty()) break;
			if (cont[i] >= boxes[boxes.size() - 1]) {
				boxes.pop_back();
			}
			else {
				for (int j = boxes.size() - 2; j >= 0; j--) {
					if (cont[i] >= boxes[j]) {
						boxes.erase(boxes.begin()+j);
						break;
					}
				}
			}
		}
		result += 1;
	}
	cout << result << '\n';
}