#include <string>
#include <vector>
#include <iostream>
using namespace std;

int N, T, P;
int person[6];

int main(){
    cin>>N;
    for(int i = 0;i<6;i++){
        cin>>person[i];
    }
    cin>>T>>P;

    int num = 0;

    for(int i = 0;i<6;i++){
        if(person[i] % T)
            num += person[i] / T + 1;
        else
            num += person[i] / T;
    }
    cout<<num<<'\n';
    cout<<N/P<<' '<<N%P<<'\n';
}