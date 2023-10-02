#include <iostream>
using namespace std;

int main(){
    int n1,n2;
    cin>>n1>>n2;
    unsigned long max, min;
    int t = 0;
    if(n1>n2) t = n2;
    else t = n1;
    for(int i =t;i>0;i--){
        if(n1%i==0&&n2%i==0){
            max = i;  
            break;
        } 
    }
    min = (n1/max) * (n2/max) * max;
    
    cout<<max<<'\n';
    cout<<min<<'\n';
}