#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N,M;
int visited[51];
int party[51][51];
int graph[51][51];
vector<int> truePerson;


void searchGraph(int p) {
	visited[p] = 1;
	
	for (int i = 1; i <= N; i++) {
		if (!graph[p][i])continue;
		
		if (visited[i]) continue;

		searchGraph(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	int trueNum;
	int num;
	cin >> trueNum;
	for (int i = 0; i < trueNum; i++) {
		cin >> num;
		truePerson.push_back(num);
	}
	for (int i = 0; i < M; i++) {
		cin >> num;
		int center;
		cin >> center;
		party[i][0] = center;
		for (int j = 1; j < num; j++) {
			cin >> party[i][j];
			graph[center][party[i][j]] = 1;
			graph[party[i][j]][center] = 1;
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < truePerson.size(); k++) {
				if (party[i][j] == truePerson[k]) {
					searchGraph(party[i][j]);
				}
			}
		}
	}

	int result = 0;
	for (int i = 0; i < M; i++) {
		bool counter = true;
		for (int j = 0; j < N; j++) {
			if (!party[i][j]) continue;

			int np = party[i][j];
			if (visited[np]) {
				counter = false;
				break;
			}
		}
		if (counter) result += 1;
	}
	cout << result << '\n';
	
}