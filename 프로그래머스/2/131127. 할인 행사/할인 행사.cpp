#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    
    for(int i = 0;i<discount.size();i++){
        unordered_map<string, int> want_map;
        if(i+10 > discount.size())
            break;
        
        for(int j = i;j<i+10;j++){
            want_map[discount[j]]++;
        }
        bool isClear = false;
        for(int j = 0;j<want.size();j++){
            if(want_map[want[j]] != number[j]){
                isClear = false;
                break;
            }
            isClear = true;
        }
        if(isClear){
            answer++;
        }
    }
    return answer;
}