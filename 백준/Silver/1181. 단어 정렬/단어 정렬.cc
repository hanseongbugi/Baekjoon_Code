#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(string a, string b){
    if(a.length()==b.length()){
        return a < b;
    }
    else {
        return a.length() < b.length();
    }
}

int main(){
    int N;
    cin>>N;
    vector<string> arr;
    arr.assign(N,"");
    for(int i =0;i<N;i++){
        string input;
        cin>>input;
        arr[i] = input;
    }
    sort(arr.begin(),arr.end(),compare);
    
    for(int i =0;i<arr.size();i++){
        if(i == arr.size()-1){
            cout<<arr[i]<<'\n';
            continue;
        }
        if(arr[i]!=arr[i+1])
            cout<<arr[i]<<'\n';
    }
}