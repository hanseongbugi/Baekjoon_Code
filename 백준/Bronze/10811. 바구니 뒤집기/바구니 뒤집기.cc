#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    int N,M;
    cin>>N>>M;
    vector<int> arr;
    arr.assign(N,0);
    for(int i =0;i<N;i++)
        arr[i] = i+1;
    
    for(int i =0;i<M;i++){
        int j,k;
        cin>>j>>k;
        reverse(arr.begin()+(j-1),arr.begin()+k);
    }
    for(int i =0;i<arr.size();i++)
        cout<<arr[i]<<' ';
    cout<<'\n';
}