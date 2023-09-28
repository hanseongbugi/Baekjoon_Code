#include<iostream>
using namespace std;

int main(){
    int N;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i =0;i<N;i++){
        int a,b;
        cin>>a>>b;
        cout<<"Case #"<<i+1<<": "<<a+b<<'\n';
    }
}