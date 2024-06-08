#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<char,int> m;

vector<int> solution(string s) {
    vector<int> answer;
    for(int i = 0;i<s.length();i++){
        m[s[i]] = -1;
    }
    for(int i = 0;i<s.length();i++){
        char c = s[i];
        if(m[c] == -1){
            m[c] = i;
            answer.push_back(-1);
        }
        else{
            answer.push_back(i - m[c]);
            m[c] = i;
        }
    }
    return answer;
}