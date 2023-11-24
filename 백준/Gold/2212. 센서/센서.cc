#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N,K;

bool sorter(int a, int b) {
	return a > b;
}
int main() {
	cin >> N;
	cin >> K;

	vector<int> sensors;
	for (int i = 0; i < N; i++) {
		int sensor;
		cin >> sensor;
		sensors.push_back(sensor);
	}
	sort(sensors.begin(), sensors.end());

	vector<int> distance;
	for (int i = 0; i < N - 1; i++) {
		distance.push_back(sensors[i + 1] - sensors[i]);
	}
	if (distance.empty()) {
		cout << 0 << '\n';
		return 0;
	}
	sort(distance.begin(), distance.end());

	for (int i = 0; i < K - 1; i++)
		distance.pop_back();

	int result = 0;
	for (int i = 0; i < distance.size(); i++)
		result += distance[i];

	cout << result << '\n';
}