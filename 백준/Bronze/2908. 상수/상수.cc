#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string n1, n2;
    cin>>n1>>n2;
    reverse(n1.begin(),n1.end());
    reverse(n2.begin(),n2.end());
    int Rn1 = stoi(n1);
    int Rn2 = stoi(n2);
    if(Rn1>Rn2) cout<<Rn1<<'\n';
    else cout<<Rn2<<'\n';
}