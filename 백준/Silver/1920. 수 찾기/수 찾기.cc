#include<iostream>
#include<map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin>>N;
    map<int,bool> m;
    for(int i = 0;i<N;i++){
        int input;
        cin>>input;
        m[input] = true;
    }
    int M;
    cin>>M;
    for(int i = 0;i<M;i++){
        int target;
        cin>>target;
        if(m.find(target)!=m.end()){
            cout<<1<<'\n';
        }
        else{
            cout<<0<<'\n';
        }
    }
}