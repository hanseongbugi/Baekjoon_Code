#include <string>
#include <vector>

using namespace std;

int dp[100001];

int calc(int n){
    int num = 0;
    for(int i = 1;i<=n/2;i++){
        if(n % i ==0)
            num++;
    }
    return num + 1;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    for(int i = 1;i<=100000;i++){
        dp[i] = calc(i);
    }
    
    for(int i = 1;i<=number;i++){
        int sword = dp[i];
        if(sword > limit)
            sword = power;
        
        answer += sword;
    }
    return answer;
}