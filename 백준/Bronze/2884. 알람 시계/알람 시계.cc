#include<iostream>
using namespace std;

int main(){
    int H,M,T;
    cin>>H>>M;

    T = H*60+M;
    T-=45;
    if(T<0){
        T = 24*60 + M;
        T -= 45;
    }
    cout<<T/60<<' '<<T%60<<'\n';
}