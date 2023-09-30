#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    for(int i =0;i<N;i++){
        string str;
        cin>>str;
        cout<<str[0]<<str[str.length()-1]<<'\n';
    }
}