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
    unordered_map<string, int> nameMap;
    unordered_map<int, string> numMap;
    string name;
    for(int i = 1;i<=N;i++){
        cin>>name;
        nameMap[name] = i;
        numMap[i] = name;
    }
    string input;
    for(int i = 0;i<M;i++){
        cin>>input;
        if(input[0] >= '0' && input[0] <= '9'){
            cout<<numMap[stoi(input)]<<'\n';
        }
        else
            cout<<nameMap[input]<<'\n';
        
    }
}