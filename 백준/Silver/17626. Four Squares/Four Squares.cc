#include <iostream>
using namespace std;

int dp[50005];
int N;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin>>N;
	
    for(int i = 1;i<=N;i++){
        dp[i] = dp[i - 1] + 1;
        for(int j = 1;j * j <=i;j++)
            dp[i] = min(dp[i],dp[i-j*j]+1);
    }
    cout<<dp[N];
}