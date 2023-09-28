#include<iostream>
using namespace std;

int main(){
    int N;
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>N;
    for(int i =0;i<N;i++){
        int a,b;
        cin>>a>>b;
        cout<<a+b<<'\n';
    }
}