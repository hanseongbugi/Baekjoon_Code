#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    vector<int> arr;
    arr.assign(N,0);
    for(int i =0;i<N;i++)
        arr[i]=i+1;
    for(int i = 0;i<M;i++){
        int a,b;
        cin>>a>>b;
        int temp = arr[a-1];
        arr[a-1] = arr[b-1];
        arr[b-1] = temp;
    }
    for(int i =0;i<arr.size();i++)
        cout<<arr[i]<<' ';
    cout<<'\n';
}