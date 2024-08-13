#include <string>
#include <vector>
#include <iostream>
using namespace std;

int L;
long long r = 1, M = 1234567891;
string str;

int main(){
    cin>>L;
    cin>>str;
    long long hashNum = 0;
    for(int i = 0;i<L;i++){
        char c = str[i];
        long long hash = c - 96;
        hashNum = (hashNum + hash * r) % M;
        r = (r * 31) % M;
    }
    cout<<hashNum<<'\n';
}