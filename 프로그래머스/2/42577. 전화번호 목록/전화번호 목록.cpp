#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

bool bigger(string a, string b){
    if(a.length()<b.length())
        return true;
    else
        return false;
}

bool solution(vector<string> phone_book) {
    unordered_map<string,int> m;
    sort(phone_book.begin(),phone_book.end(),bigger);
    
    int minLen = 21;
    for(int i = 0;i<phone_book.size();i++){
        string number = phone_book[i];
        int numberLen = number.length();
        minLen = min(minLen, numberLen);
        if(m.empty())
            m[number] = 1;
        else{
            string temp = string(number.begin(),number.begin()+minLen);
            for(int j = minLen;j<number.length();j++){
                if(m[temp] == 1)
                    return false;
                temp += number[j];
                
            }
            m[number] = 1;
        }
    }
    return true;
}