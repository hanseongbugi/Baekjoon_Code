#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<string, int> m;
    cin >> N >> M;
    string name;
    for (int i = 0; i < N; i++) {
        cin >> name;
        m[name] = 1;
    }

    vector<string> v;
    for (int i = 0; i < M; i++) {
        cin >> name;
        if (m[name] == 1) {
            v.push_back(name);
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << '\n';

    return 0;
}