#include <iostream>
#include <string>
#include <vector>
using namespace std;

string infix;
string postfix;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>infix;
    vector<char> v;

    for(int i = 0;i<infix.length();i++){
        char c = infix[i];

        if(c == '('){
            v.push_back(c);
        }
        else if(c == '*' || c == '/'){
            while(!v.empty() && (v.back() == '*' || v.back() == '/')){
                
                postfix += v.back();
                v.pop_back();
            }
            v.push_back(c);
        }
        else if(c == '+' || c == '-'){
            while(!v.empty()){
                if(v.back() == '(')
                    break;
                postfix += v.back();
                v.pop_back();  
            }
            v.push_back(c);
        }
        else if(c == ')'){
            while(!v.empty()){
                if(v.back() == '(')
                    break;
                postfix += v.back();
                v.pop_back();  
            }
            v.pop_back();
        }
        else{
            postfix += c;
        }
    }
    while(!v.empty()){
        postfix += v.back();
        v.pop_back();
    }

    cout<<postfix;
}