#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    while(true){
        string str;
        cin>>str;
        if(str=="0") break;
        string original = str;
        reverse(str.begin(),str.end());
        if(str==original) cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';
    }
}