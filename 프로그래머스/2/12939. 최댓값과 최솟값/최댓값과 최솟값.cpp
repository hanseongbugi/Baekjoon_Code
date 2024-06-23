#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> v;
    string num = "";
    for(int i = 0;i<s.length();i++){
        if(s[i] == ' '){
            v.push_back(stoi(num));
            num = "";
        }
        else{
            num += s[i];
        }
    }
    v.push_back(stoi(num));
    sort(v.begin(),v.end());
    
    answer += to_string(v[0]);
    answer += " ";
    answer += to_string(v[v.size()-1]);
    return answer;
}