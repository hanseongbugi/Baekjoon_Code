#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string,bool> m;
    
    int pNum = 1, counter = 1;
    int answerNum = 0, answerCounter = 0;
    char lastChar = words[0][0];
    for(int i = 0;i<words.size();i++){
        if(lastChar != words[i][0]){ // 규칙 3 위배
            answerNum = pNum;
            answerCounter = counter;
            break;
        }
        if(m.find(words[i]) != m.end()){ // 규칙 4 위배
            answerNum = pNum;
            answerCounter = counter;
            break;
        }
        if(words[i].length()==1){ // 규칙 5 위배
            answerNum = pNum;
            answerCounter = counter;
            break;
        }
        lastChar = words[i][words[i].length() - 1];
        pNum++;
        if(pNum > n){
            pNum = 1;
            counter++;
        }
        m[words[i]] = true;
    }
    
    answer.push_back(answerNum);
    answer.push_back(answerCounter);
    return answer;
}