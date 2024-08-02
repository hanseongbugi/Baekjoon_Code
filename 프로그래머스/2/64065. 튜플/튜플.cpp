#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool bigger(vector<int> a, vector<int> b){
    if(a.size() < b.size())
        return true;
    else
        return false;
}
vector<vector<int>> makeElement(string s){
    vector<vector<int>> v;
    vector<int> stack;
    string temp = "";
    for(int i = 0;i<s.length();i++){
        if(s[i] == '{')
            continue;
        
        else if(s[i] == ','){
            if(temp != "")
                stack.push_back(stoi(temp));
            temp = "";
        }
            
        else if(s[i] == '}'){
            if(temp != "")
                stack.push_back(stoi(temp));
            if(!stack.empty())
                v.push_back(stack);
            stack.resize(0);
            temp = "";
        }
        else 
            temp += s[i];
        
    }
    sort(v.begin(),v.end(),bigger);
    return v;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<vector<int>> v = makeElement(s);
    // 2
    // 2 1
    // 1 2 3
    // 1 2 4 3
    for(int i = 0;i<v.size();i++){
        for(int j = 0;j<v[i].size();j++)
            if(find(answer.begin(),answer.end(),v[i][j])==answer.end())
                answer.push_back(v[i][j]);
        
    }
    
    return answer;
}