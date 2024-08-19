#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int T, N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>T;
    for(int i = 0;i<T;i++){
        cin>>N;
        string name, type;
        unordered_map<string, int> m;
        
        for(int j = 0;j<N;j++){
            cin>>name>>type;
            m[type]++;
        }
        int answer = 1;
        for(auto e : m)
            answer *= (e.second + 1);
        
        answer--;
        cout<<answer<<'\n';
    }
}