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
    
    for(int i = 0;i<N;i++)
        cin>>arr[i].first>>arr[i].second;

    
    for(int i = 1;i<=100000;i++){
       for(int j = 0;j<N;j++){
            if(i%arr[j].first == 0){
                dp[i] = max(dp[i], (i/arr[j].first)*arr[j].second);
            }
            if(i-arr[j].first >= 0){
                dp[i] = max(dp[i], dp[i-arr[j].first] + arr[j].second);
            }
       }
       if(C<=dp[i]){
            cout<<i<<'\n';
            break;
       }
    }
    
    
    return 0;
}