#include<iostream>
#include<cstring>
using namespace std;

int C, N;
pair<int,int> arr[21];
int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    cin>> C >> N;
    
    for(int i = 1;i<=N;i++)
        cin>>arr[i].first>>arr[i].second;

    
    for(int i = 1;i<=N;i++){
        for(int j = 1;j<=100000;j++){
            if(j-arr[i].first >= 0){
                dp[j] = max(dp[j], dp[j-arr[i].first] + arr[i].second);
            }
        }
    }
    for(int i = 1;i<=100000;i++){
        if(dp[i]>=C){
            cout<<i<<'\n';
            break;
        }
    }
    
    return 0;
}