#include<iostream>
#include<cstring>
using namespace std;

int N, K;
int arr[5001];
bool dp[5001];

void dfs(int rock){
    if(rock == N){
        dp[rock] = true;
        return;
    }
    if(dp[rock]) return;

    dp[rock] = true;
    for(int i = rock + 1;i<=N;i++){
        if((i-rock) * (1 + abs(arr[rock - 1] - arr[i - 1]))<=K)
            dfs(i);
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    cin>> N >> K;
    for(int i = 1;i<=N;i++)
        cin>>arr[i];
    
    dp[1] = true;

    for(int i = 1; i<=N;i++){
        if(!dp[i]) continue;
        for(int j = i+1;j<=N;j++){
            long long now = (j-i) * (1 + abs(arr[i] - arr[j]));
            if(now <= K)
                dp[j] = true;
        }
        if(dp[N]){
            cout<<"YES"<<'\n';
            exit(0);
        }
    }
    cout<<"NO"<<'\n';
    return 0;
}