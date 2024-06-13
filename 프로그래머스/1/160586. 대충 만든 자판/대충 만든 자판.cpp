#include <string>
#include <vector>
#include <map>
using namespace std;

map<char, int> key;
vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    for(char i = 'A';i<='Z';i++)
        key[i] = 101;
    
    for(int i = 0;i<keymap.size();i++){
        for(int j = 0;j<keymap[i].length();j++){
            key[keymap[i][j]] = min(key[keymap[i][j]], j+1);
        }
    }
    
    for(int i = 0;i<targets.size();i++){
        int total = 0;
        for(int j = 0;j<targets[i].length();j++){
            char t = targets[i][j];
            if(key[t] > 100){
                total = -1;
                break;
            }
            total += key[t];
        }
        answer.push_back(total);
    }
    return answer;
}