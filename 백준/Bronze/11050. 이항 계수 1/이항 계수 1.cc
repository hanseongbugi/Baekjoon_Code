#include<iostream>
using namespace std;

long calc(int n){
    long sum = 1;
    for(int i = 1;i<=n;i++){
        sum *= i;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,K;
    cin>>N>>K;
    
    long result = calc(N)/(calc(K) * calc(N-K));
    cout<<result<<'\n';
}