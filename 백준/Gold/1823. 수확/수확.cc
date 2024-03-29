#include<iostream>
#include<algorithm>
using namespace std;
 
int N;
int rice[2001];
int dp[2001][2001];

int solve(int start, int end, int counter){
    if(start > end) return 0;

    if(dp[start][end])
        return dp[start][end];
    
    return dp[start][end] = max(solve(start+1, end, counter + 1)+ rice[start] * counter,
        solve(start, end-1,counter + 1) + rice[end] * counter);
}
 
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>rice[i];

    cout<<solve(0, N - 1, 1)<<'\n';
}
