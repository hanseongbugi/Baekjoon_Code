#include <string>
#include <vector>

using namespace std;

long long dp[21];
vector<int> solution(int n, long long k) {
    vector<int> answer,v;
    for(int i=1; i<=n;i++){
        v.push_back(i);
    }
    if(k==1)
        return v;
    
    dp[1] = 1;
    for(int i = 2;i<=n;i++)
        dp[i] = i * dp[i-1];
    
    k-=1;
    long long pre = dp[n];
    long long mod,div;

    while(v.size()!=1){
        pre /= n;
        mod = k % pre;
        div = k / pre;
        answer.push_back(v[div]);
        v.erase(v.begin() + div);
        k = mod;
        n--;
    }
    answer.push_back(v[0]);
    return answer;
}