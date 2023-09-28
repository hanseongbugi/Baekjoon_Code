#include<iostream>
using namespace std;

int main(){
    int N,M;
    cin>>N;
    cin>>M;
    cout<<N * (M%10)<<'\n';
    cout<<N * ((M%100)/10)<<'\n';
    cout<<N * (M/100)<<'\n';
    cout<<N * M <<'\n';
}