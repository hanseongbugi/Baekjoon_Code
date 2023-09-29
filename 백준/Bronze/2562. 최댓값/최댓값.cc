#include<iostream>
using namespace std;

int main(){
    int max = 0, index= 0;
    for(int i =0;i<9;i++){
        int N;
        cin>>N;
        if(max<N){
            max = N;
            index = i+1;
        }
    }
    cout<<max<<'\n';
    cout<<index<<'\n';
}