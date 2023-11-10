#include <iostream>
#include<queue>
using namespace std;
int N, K;
int main() {
	cin >> N >> K;
	queue<int> q;
	vector<int> result;
	int counter = 1;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	int check = 1;
	while (result.size()!=N) {
		int value = q.front();
		q.pop();
		if (check == K) {
			result.push_back(value);
			check = 0;
		}
		else {
			q.push(value);
		}
		check += 1; 
	}

	cout << "<";
	for (int i = 0; i < result.size() - 1; i++)
		cout << result[i] << ", ";
	cout << result[result.size() - 1] << ">" << '\n';
}