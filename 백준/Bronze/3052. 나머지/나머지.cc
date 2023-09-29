#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> arr;
    for(int i =0;i<10;i++){
        int N;
        cin>>N;
        arr.insert(N%42);
    }
    cout<<arr.size()<<'\n';
}