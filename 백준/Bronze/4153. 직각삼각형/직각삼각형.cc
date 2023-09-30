#include<iostream>
using namespace std;

int main(){
    while(true){
        unsigned long A,B,C;
        cin>>A>>B>>C;
        if(A==0&&B==0&&C==0) break;
        if(A*A+B*B==C*C||A*A==B*B+C*C||B*B==A*A+C*C) cout<<"right"<<'\n';
        else cout<<"wrong"<<'\n';
    }
}