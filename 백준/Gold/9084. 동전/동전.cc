#include<iostream>
#include<cstring>
using namespace std;

int T,N,M;
int coin[10001];
int dp[10001];
int target = 0;

void solve(){
    dp[0] = 1;
    for(int i = 0;i<N;i++){
        for(int j = coin[i];j<=target;j++)
            dp[j] += dp[j - coin[i]];
    }
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    // Test case input
    cin>>T;
    for(int i = 0;i<T;i++){
        memset(dp, 0, sizeof(dp));

        // coin input
        cin>>N; 
        for(int j = 0;j<N;j++)
            cin>>coin[j];
        
        // target value input
        cin>>target;

        // dynamic programming
        solve();
        cout<<dp[target]<<'\n';
    }
    
    
    return 0;
}