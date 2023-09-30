#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    int N;
    cin>>N;
    
    cin>>str;
    int sum=0;
    for(int i =0;i<N;i++){
        sum+=str.at(i) - '0';
    }
    cout<<sum<<'\n';
}