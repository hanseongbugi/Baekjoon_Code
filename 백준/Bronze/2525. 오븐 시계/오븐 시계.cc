#include<iostream>
using namespace std;

int main(){
    int H,M,C,T;
    cin>>H>>M;
    cin>>C;
    T = H*60+M+C;
    if(T/60>=24){
        cout<<T/60-24<<' '<<T%60<<'\n';
    }else{
        cout<<T/60<<' '<<T%60<<'\n';
    }
    
}