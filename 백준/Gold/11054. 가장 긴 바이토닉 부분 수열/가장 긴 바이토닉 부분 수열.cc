#include <iostream>
using namespace std;

int N;
int A[1000];

int dp[1000];
int rdp[1000];
int answer = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>A[i];
    
    // 증가하는 수열 중 가장 긴 것
    for(int i = 0;i<N;i++){
        dp[i] = 1;
        for(int j = 0;j<=i;j++){
            if(A[j] < A[i] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }

    // 감소하는 수열 중 가장 긴 것
    for(int i = N-1;i>=0;i--){
        rdp[i] = 1;
        for(int j = N-1;j>=i;j--){
            if(A[i] > A[j] && rdp[j] + 1 > rdp[i])
                rdp[i] = rdp[j] + 1;
        }
    }

    for(int i = 0;i<N;i++)
        answer = max(answer,dp[i] + rdp[i] - 1);
    
    cout<<answer;
}   