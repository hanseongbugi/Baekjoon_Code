#include <string>
#include <vector>
#include <iostream>
using namespace std;

string calc(string s){
    string temp = "";
    if(s[0] >= '0' && s[0] <= '9'){
        temp += s[0];
    }
    else{
        if(s[0] >= 'A' && s[0] <= 'Z')
            temp += s[0];
        else{
            temp += s[0] - 32;
        }
    }
    for(int i = 1;i<s.length();i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
            temp += s[i] + 32;
        else
            temp += s[i];
    }
    
    return temp;
}

string solution(string s) {
    string answer = "";

    int idx = 0;
    string temp = "";
    for(int i = 0;i < s.length();i++){
        if(s[i] == ' '){
            if(!temp.empty()){
                temp = calc(temp);
                answer += temp;
            }
            answer += " ";
            temp = "";
        }
        else{
            temp += s[i];
        }
    }
    if(!temp.empty()){
        temp = calc(temp);
        answer += temp;
    }
    return answer;
}