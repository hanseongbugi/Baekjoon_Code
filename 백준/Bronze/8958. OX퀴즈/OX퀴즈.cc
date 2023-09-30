#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    string str;
    for(int i=0;i<N;i++){
        cin>>str;
        int sum = 0, sucess=0;
        for(int j =0;j<str.length();j++){
            char c = str[j];
            if(c=='O'){
                sucess += 1;
                sum+=sucess;
            }
            else sucess = 0;
        }
        cout<<sum<<'\n';
    }
}