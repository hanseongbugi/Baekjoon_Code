#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

int T, N;
long long dp[101];
int number[] = {0,0,1,7,4,2,0,8};
string bigger;

void findMaxNumber(int stick){
    if(stick == 0) return;
    
    if(stick == 3){
        bigger += "7";
        return;
    }
    bigger += "1";
    findMaxNumber(stick-2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    // dp 배열 초기화
    memset(dp,0x7f,sizeof(dp)); 
    dp[1] = 9; dp[2] = 1; dp[3] = 7;
    dp[4] = 4; dp[5] = 2; dp[6] = 6;
    dp[7] = 8;

    for(int i = 8;i<=100;i++){
        for(int j = 2;j<=7;j++){
            dp[i] = min(dp[i], dp[i-j]*10+number[j]);
        }
    }

    cin>>T;
    for(int i = 0;i<T;i++){
        cin>>N;
        bigger = "";
        findMaxNumber(N);
        reverse(bigger.begin(),bigger.end());
        cout<<dp[N]<<' '<<bigger<<'\n';
    }
    
    
    return 0;
}