#include<string>
#include <iostream>
#include <vector>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    vector<char> v;
    
    while(!s.empty()){
        char c = s.back();
        s.pop_back();
        if(c == ')'){
            v.push_back(c);
        }
        else{
            if(v.empty())
                return false;
            else{
                char s = v.back();
                if(s == ')')
                    v.pop_back();
                else
                    return false;
            }
        }
    }
    if(!v.empty()) return false;
    
    return true;
}