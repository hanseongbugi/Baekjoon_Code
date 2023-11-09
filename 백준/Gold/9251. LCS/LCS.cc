#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int dp[1001][1001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;

    cin >> a >> b;
    
    //1. dp[i][j] = dp[i-1][j-1]+1;
    //2. dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j-1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[a.length()][b.length()];

    return 0;
}