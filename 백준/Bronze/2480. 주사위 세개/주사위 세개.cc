#include<iostream>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    if(a==b){
        if(b==c)
            cout<<10000+a*1000<<'\n';
        else
            cout<<1000+a*100<<'\n';
    }
    else if(a==c){
        if(b==c)
            cout<<10000+a*1000<<'\n';
        else
            cout<<1000+a*100<<'\n';
    }
    else if(b==c){
        if(a==b)
            cout<<10000+b*1000<<'\n';
        else
            cout<<1000+b*100<<'\n';
    }
    else{
        int max = 0;
        if(a>max) max = a;
        if(b>max) max = b;
        if(c>max) max = c;
        cout<<max*100<<'\n';
    }
}