#include<iostream>
#include<vector>
using namespace std;

int main(){
    int A,B,C;
    vector<int> arr;
    arr.assign(10,0);
    cin>>A;
    cin>>B;
    cin>>C;
    unsigned long sum = A*B*C;
    string calc = to_string(sum);
    for(int i =0;i<calc.length();i++){
        arr[calc[i]-'0'] += 1;
    }
    for(int i =0;i<arr.size();i++)
        cout<<arr[i]<<'\n';
}