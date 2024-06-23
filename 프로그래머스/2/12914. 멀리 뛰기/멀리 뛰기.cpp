#include <string>
#include <vector>
using namespace std;

long long dp[2001];

long long solution(int n) {
    long long answer = 0;
    
    // dp[1] = 1  -> 1
    // dp[2] = 2  -> 1 1, 2
    // dp[3] = 3  -> 1 1 1, 2 1, 1 2
    // dp[4] = 5  -> 1 1 1 1, 1 1 2, 2 1 1, 1 2 1, 2 2
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3;i<=n;i++)
        dp[i] = (dp[i-2] + dp[i-1]) % 1234567;
    
    answer = dp[n];
    return answer;
}