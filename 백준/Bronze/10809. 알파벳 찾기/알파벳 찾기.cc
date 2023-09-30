#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr;
    arr.assign(26, -1);
    string str;
    cin>>str;
    for(int i =0;i<str.length();i++){
        char c = str.at(i);
        if(arr[c-'a']==-1)
            arr[c-'a'] = i;
    }
    for(int i =0;i<arr.size();i++)
        cout<<arr[i]<<' ';
    cout<<'\n';
}