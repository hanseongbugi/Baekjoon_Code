#include <iostream>
#include <algorithm>
using namespace std;
int N, M, arr[9], result[9]; 
int visited[9] = { 0, };

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", result[i]);
		printf("\n");
		return;
	}
	int num = 0;
	for (int i = 0; i < N; i++) {
		if (!visited[i] && arr[i] != num) {
			result[cnt] = arr[i];
			num = result[cnt];
			visited[i] = 1;
			dfs(cnt + 1);
			visited[i] = 0;
		}
	}
}
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	dfs(0);
}