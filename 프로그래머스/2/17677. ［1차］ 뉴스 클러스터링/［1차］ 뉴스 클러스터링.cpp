#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string calc(string str){
    string temp = "";
    
    for(int i = 0;i<str.length();i++){
        if(str[i] >= 'A' && str[i] <= 'Z')
            temp += str[i] + 32;
        else
            temp += str[i];
    }
    return temp;
}
int solution(string str1, string str2) {
    int answer = 0;
    double interNum = 0;
    vector<string> v_union;
    vector<string> v_inter1;
    vector<string> v_inter2;
    for(int i = 0;i<str1.length()-1;i++){
        string temp = "";
        if(!isalpha(str1[i]) || !isalpha(str1[i+1]))
            continue;
        
        temp += str1[i];
        temp += str1[i+1];
        temp = calc(temp);
        v_inter1.push_back(temp);
    }
    
    for(int i = 0;i<str2.length()-1;i++){
        string temp = "";
        if(!isalpha(str2[i]) || !isalpha(str2[i+1]))
            continue;
        
        temp += str2[i];
        temp += str2[i+1];
        temp = calc(temp);
        v_inter2.push_back(temp);
    }
    // fr ra an nc ce
    // fr re en nc ch
    while(!v_inter1.empty()){
        string temp = v_inter1.back();
        v_inter1.pop_back();
        v_union.push_back(temp);
        
        auto iter = find(v_inter2.begin(),v_inter2.end(),temp);
        if(iter != v_inter2.end()){
            interNum++;
            v_inter2.erase(iter);
        }
    }
    while(!v_inter2.empty()){
        string temp = v_inter2.back();
        v_inter2.pop_back();
        v_union.push_back(temp);
    }

    if(v_union.empty() && interNum == 0)
        answer = 65536;
    else{
        if(v_union.empty())
            answer = 0;
        else if(interNum == 0)
            answer = 0;
        else{
            answer = (interNum / v_union.size()) * 65536;
        }
    }
    // aa aa 
    // aa aa aa 
    return answer;
}