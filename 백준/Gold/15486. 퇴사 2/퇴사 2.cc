#include<iostream>
using namespace std;

int N;
pair<int,int> arr[1500001];
int dp[1500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    cin>>N;
    for(int i = 1;i<=N;i++)
        cin>>arr[i].first>>arr[i].second;
    
    int result = 0;
    for(int i = 1;i<=N+1;i++){
        result = max(result, dp[i]);
        dp[i+arr[i].first] = max(result + arr[i].second, dp[i + arr[i].first]);
    }

    cout<<result<<'\n';
    return 0;
}