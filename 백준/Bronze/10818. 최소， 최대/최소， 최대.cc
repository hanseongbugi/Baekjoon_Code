#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> arr;
    arr.assign(N,0);
    for(int i = 0;i<N;i++){
        int a;
        cin>>a;
        arr[i] = a;
    }
    sort(arr.begin(),arr.end());
    cout<<arr[0]<<' '<<arr[N-1]<<'\n'; 
}