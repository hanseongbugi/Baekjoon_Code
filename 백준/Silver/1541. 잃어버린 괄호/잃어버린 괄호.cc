#include<iostream>
#include<string>
using namespace std;

string N;
string arr[50];
int main() {
	cin >> N;

	string number = "";
	int index = 0;
	for (int i = 0; i < N.length(); i++) {
		char c = N[i];

		if (c == '+' || c == '-') {
			arr[index++] = number;
			arr[index++] = c;

			number = "";
		}
		else {
			number += c;
		}
	}
	if (!number.empty()) arr[index++] = number;

	bool minFlag = false;
	int result = stoi(arr[0]);

	for (int i = 1; i < index - 1; i+=2) {
		if (arr[i] == "-") minFlag = true;

		if(minFlag){
			result -= stoi(arr[i + 1]);
		}
		else {
			if (arr[i] == "-") result -= stoi(arr[i + 1]);
			else result += stoi(arr[i + 1]);
		}
	}
	cout << result << '\n';
}