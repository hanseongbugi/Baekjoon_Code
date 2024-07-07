#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    int n = s.length();
    for(int i = 0;i<n;i++){
        vector<char> v;
        bool isClear = true;
        for(int j = 0;j<n;j++){
            if(s[j] == '[' || s[j] == '(' || s[j] == '{'){
                v.push_back(s[j]);
            }
            else{
                if(v.empty()){
                    isClear = false;
                    break;
                }
                char vc = v.back();
                if((vc == '{' && s[j] == '}')||(vc == '(' && s[j] == ')')||(vc == '[' && s[j] == ']'))
                    v.pop_back();
                else{
                    isClear = false;
                    break;
                }
            }
        }
        if(isClear && v.empty())
            answer++;
        s.push_back(s[0]);
        s.erase(s.begin());
    }
    return answer;
}