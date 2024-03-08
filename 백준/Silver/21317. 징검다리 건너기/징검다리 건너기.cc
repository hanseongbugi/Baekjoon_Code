#include<iostream>
using namespace std;

int N, K;
pair<int,int> arr[21];
int dp[21][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    cin>>N;
    for(int i = 1;i<N;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    cin>>K;
    for(int i = 0;i<=N;i++){
        dp[i][0] = 999999;
        dp[i][1] = 999999;
    }
    dp[1][0] = 0;
    dp[2][0] = arr[1].first;
    dp[3][0] = min(arr[1].first + arr[2].first,arr[1].second);
    for(int i =4;i<=N;i++){
        dp[i][0] = min(arr[i-1].first + dp[i-1][0],arr[i-2].second + dp[i-2][0]);
        dp[i][1] = min(min(arr[i-1].first+dp[i-1][1], arr[i-2].second+ dp[i-2][1]),K+dp[i-3][0]);
    }
    cout<<min(dp[N][0],dp[N][1])<<'\n';
    return 0;
}