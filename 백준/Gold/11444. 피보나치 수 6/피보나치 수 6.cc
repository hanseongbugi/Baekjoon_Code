#include <iostream>
#include <map>
using namespace std;

long long N;
map<long long, long long> f;

long long fibo(long long num){
    if(num == 0) return 0;
    if(num == 1) return 1;
    if(num == 2) return 1;
    if(f.count(num) > 0) return f[num];

    if(num % 2 == 0){
        long long m = num / 2;
        long long temp1 = fibo(m - 1);
        long long temp2 = fibo(m);
        f[num] = ((2 * temp1 + temp2) * temp2) % 1000000007;
        return f[num];
    }
    long long m = (num + 1) / 2;
    long long temp1 = fibo(m);
    long long temp2 = fibo(m - 1);
    f[num] = (temp1 * temp1 + temp2 * temp2) % 1000000007;
    return f[num];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;
    cout<<fibo(N);

}   