#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int K;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>K;
    vector<int> v;
    int num;
    for(int i = 0;i<K;i++){
        cin>>num;

        if(num == 0){
            if(!v.empty())
                v.pop_back();
        }
        else{
            v.push_back(num);
        }
    }
    int answer = 0;
    for(int i = 0;i<v.size();i++)
        answer += v[i];
    cout<<answer<<'\n';
}