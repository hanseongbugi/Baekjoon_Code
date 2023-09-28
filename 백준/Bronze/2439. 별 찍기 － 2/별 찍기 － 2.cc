#include<iostream>
using namespace std;

int main(){
    int N;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i = 0;i<N;i++){
        for(int j = N-i;j>1;j--){
            cout<<" ";
        }
        for(int k = 0;k<=i;k++){
            cout<<"*";
        }
        cout<<'\n';
    }
}