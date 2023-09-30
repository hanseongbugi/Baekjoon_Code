#include<iostream>
#include<string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str; 
    int count = 0;
    getline(cin,str,'\n');
    for(int i =0;i<str.length();i++){
        if(count==0){
            if(isalpha(str.at(i))) count=1;
        }
        if(i!=0&&i<str.length()-1){
            if(str.at(i-1)!=' '&&str.at(i)==' '&&str.at(i+1)!=' ')
                count+=1;
        }
    }
    cout<<count<<'\n';
}