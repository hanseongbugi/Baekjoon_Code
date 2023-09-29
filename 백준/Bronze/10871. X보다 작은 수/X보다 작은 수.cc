#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N,X;
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    cin>>N>>X;
    vector<int> arr;
    arr.assign(N,0);
    for(int i =0;i<N;i++){
        int a;
        cin>>a;
        arr[i] = a;
    }
    for(int i = 0;i<arr.size();i++){
        if(arr[i]<X) cout<<arr[i]<<' ';
    }
    cout<<'\n';
}