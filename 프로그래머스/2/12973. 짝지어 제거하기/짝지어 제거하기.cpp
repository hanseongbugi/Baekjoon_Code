#include <iostream>
#include<string>
#include <vector>
using namespace std;

int solution(string s)
{
    int answer = 0;
    vector<char> v;
    v.push_back(s[0]);
    for(int i = 1;i<s.length();i++){
        char c = s[i];
        if(v.back() == c){
            v.pop_back();
        }
        else{
            v.push_back(c);
        }
    }
    if(v.empty()) 
        answer = 1;
    

    return answer;
}