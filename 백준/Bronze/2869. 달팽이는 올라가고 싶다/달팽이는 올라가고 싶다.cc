#include <string>
#include <vector>
#include <iostream>
using namespace std;

int A, B, V;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>A>>B>>V;
    int day = 1;
    day += (V-A)/(A-B);
    
    if((V-A) % (A-B) != 0)
        day ++;
    if(A >= V)
        cout<<"1"<<'\n';
    else
        cout<<day<<'\n';
}