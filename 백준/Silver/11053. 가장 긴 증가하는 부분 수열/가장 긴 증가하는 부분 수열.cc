#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1001];
int T;
int N, M, K, H;
int X, Y;
int answer = 0;

int main() {
    vector<int> v;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> K;
        v.push_back(K);
        int dp_max = 0;

        for (int j = 0; j < v.size(); j++) {
            if (v[i] > v[j]) {
                if (dp_max < dp[j])
                    dp_max = dp[j];
            }
        }
        dp[i] = dp_max + 1;
        answer = max(answer, dp[i]);
    }

    cout << answer << endl;

    return 0;
}