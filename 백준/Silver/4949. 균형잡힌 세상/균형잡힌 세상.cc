#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(true){
        string str;
        getline(cin,str);

        if(str == ".")
            break;
        
        vector<char> v;
        bool isClear = true;

        for(int i = 0;i<str.length();i++){
            if(str[i] == '(' || str[i] == '[')
                v.push_back(str[i]);
            else if(str[i] == ')' || str[i] == ']'){
                if(v.empty()){
                    isClear = false;
                    break;
                }
                else{
                    if((v.back() == '[' && str[i] == ']') || (v.back() == '(' && str[i] == ')')){
                        v.pop_back();
                    }
                    else{
                        isClear = false;
                        break;
                    }
                }
            }
        }
        if(!v.empty())
            isClear = false;
        
        if(isClear)
            cout<<"yes"<<'\n';
        else
            cout<<"no"<<'\n';
    }
}