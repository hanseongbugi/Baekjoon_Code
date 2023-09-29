#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    vector<int> arr;
    arr.assign(N,0);
    for(int i = 0;i<N;i++){
        int a;
        cin>>a;
        arr[i] = a;
    }
    int V, count = 0;
    cin>>V;
    for(int j = 0;j<arr.size();j++){
        if(arr[j]==V)count+=1;
    }
    cout<<count<<'\n';
}