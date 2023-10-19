#include<iostream>
#include<vector>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    vector<int> arr;
    arr.assign(41, 1);
    arr[0] = 0;
    for(int i = 2;i<=40;i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    for(int i = 0;i<T;i++){
        int N;
        cin>>N;
        if(N == 0) cout<<"1 0"<<'\n';
        else cout<<arr[N-1]<<' '<<arr[N]<<'\n';
    }
}