#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> arr;
    for(int i =0;i<N;i++){
        int input;
        cin>>input;
        arr.push_back(input);
    }
    sort(arr.begin(),arr.end());
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]<<'\n';
    }
}