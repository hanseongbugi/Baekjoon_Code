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
    for(int a = 0;a<M;a++){
        int i,j,k;
        cin>>i>>j>>k;
        for(int t = i-1;t<j;t++){
            arr[t]=k;
        }
    }
    for(int i =0;i<arr.size();i++)
        cout<<arr[i]<<' ';
    cout<<'\n';
}