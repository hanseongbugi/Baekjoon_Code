#include<iostream>
#include<cstring>
using namespace std;

int N,K;
int dp[201][201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    cin>>N>>K;

    // K가 1인 경우 초기화
    for(int i = 1;i<=N;i++)
        dp[i][1] = 1;
    
    for(int j = 2;j<=K;j++)
        dp[1][j] = (dp[1][j-1] + 1) % 1000000000;

    for(int i = 2;i<=N;i++){
        for(int j = 2;j<=K;j++)
            dp[i][j] += (dp[i-1][j] + dp[i][j-1]) % 1000000000;
    }
    cout<<dp[N][K]<<'\n';
    
    return 0;
}