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
    for(int i = 0;i<str.length();i++){
        char c = str[i];
     
        hashNum += ((int)c - 'a' + 1) * r % M;
        r *= 31;
    }
    cout<<hashNum<<'\n';
}