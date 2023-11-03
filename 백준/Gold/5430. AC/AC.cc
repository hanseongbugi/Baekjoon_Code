#include <iostream>
#include <deque>
#include<string>
#include<algorithm>
using namespace std;

int len;
string x;
bool error = false;
bool rever = false;

deque<int> makeArray() {
	deque<int> arr;
	string s = "";
	for (int i = 0; i < x.length(); i++) {
		if (isdigit(x[i])) {
			s += x[i];
		}
		else {
			if (!s.empty()) {
				arr.push_back(stoi(s));
				s = "";
			}
		}
	}
	return arr;
}
void printArray(deque<int> arr) {

	cout << "[";
	if (!arr.empty()) {
		if (rever) {
			for (int i = arr.size() - 1; i > 0; i--) {
				cout << arr[i] << ",";
			}
			cout << arr[0];
		}
		else {
			for (int i = 0; i < arr.size() - 1; i++) {
				cout << arr[i] << ",";
			}
			cout << arr[arr.size() - 1];
		}
	}
	cout << "]"<<'\n';
}

void AC(deque<int>& arr, string p) {
	for (int i = 0; i < p.length(); i++) {
		if (p[i] == 'R') {
			if (rever) rever = false;
			else rever = true;

		}
		if (p[i] == 'D') {
			if (arr.empty()) {
				cout << "error" << '\n';
				error = true;
				return;
			}
			if (rever)
				arr.pop_back();
			else
				arr.pop_front();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		string p;
		cin >> p;

		cin >> len;
		cin >> x;

		deque<int> arr = makeArray();
		rever = false;
		error = false;
		AC(arr, p);

		if (!error)
			printArray(arr);

	}
}