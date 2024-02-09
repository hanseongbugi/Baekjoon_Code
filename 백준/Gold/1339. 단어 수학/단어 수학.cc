#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int N;
int value = 0;
vector<pair<char,int>> arr;
vector<string> voc;
map<char, int> m;
map<char,int, greater<int>> alpha;

bool bigger(pair<char, int>& a, pair<char, int>& b) {
	return a.second > b.second;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	string input;
	
	for (int i = 0; i < N; i++) {
		cin >> input;
		int len = input.length();
		voc.push_back(input);
		for (int j = 0; j < len; j++)
			alpha[input[j]] += pow(10, len - j);
	}
	for (auto iter = alpha.begin(); iter != alpha.end(); iter++) {
		arr.push_back({ iter->first,iter->second });
	}
	sort(arr.begin(), arr.end(), bigger);
		
	int number = 9;
	for (int i = 0; i < arr.size(); i++) {
		m[arr[i].first] = number--;
	}
	
	for (int i = 0; i < voc.size(); i++) {
		string target = voc[i];
		int len = target.length();
		string number = "";
		for (int j = 0; j < len; j++) {
			int calc = m[target[j]];
			number += to_string(calc);
		}
		value += stoi(number);
	}
	
	cout << value << '\n';
}