#include<iostream>
using namespace std;

int main(){
    int T;
    cin>>T;
    int N, sum=0;
    cin>>N;
    for(int i = 0;i<N;i++){
        int A,B;
        cin>>A>>B;
        sum+=A*B;
    }
    if(T==sum) cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';
}