#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr;
    arr.assign(8,0);
    for(int i =0;i<8;i++){
        int n;
        cin>>n;
        arr[i]=n;
    }
    bool check = true;
    for(int i =0;i<7;i++){
        if(abs(arr[i]-arr[i+1])!=1) {
            check = false;
            break;
        }
    }
    if(check){
        if(arr[0] - arr[1]==1) cout<<"descending"<<'\n';
        else cout<<"ascending"<<'\n';
    }
    else cout<<"mixed"<<'\n';
}