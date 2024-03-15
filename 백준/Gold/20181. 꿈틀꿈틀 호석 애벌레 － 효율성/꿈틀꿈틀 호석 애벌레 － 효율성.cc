#include<iostream>
using namespace std;

int N,K;
long long arr[100001];
long long dp[100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N>>K;

    for(int i = 0;i<N;i++){
        cin>>arr[i];
    }
    
    int start = 1, end = 1;
    long long temp = arr[start];

    while(start<=N&&end<=N){
        dp[end] = max(dp[end],dp[end-1]);

        if(temp>=K){
            dp[end] = max(dp[end],dp[start-1] + temp - K);
            if(start < end){
                temp -= arr[start];
                start++;
            }
            else if(start == end){
                start++;
                end++;
                temp = arr[end];
            }
        }
        else{
            end++;
            temp+=arr[end];
        }
    }
    cout<<dp[N]<<'\n';

}