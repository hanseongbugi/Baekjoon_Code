#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N,M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N>>M;
    string site, pass;
    unordered_map<string, string> m;

    for(int i = 0;i<N;i++){
        cin>>site>>pass;
        m[site] = pass;
    }
    for(int i = 0;i<M;i++){
        cin>>site;
        cout<<m[site]<<'\n';
    }
}