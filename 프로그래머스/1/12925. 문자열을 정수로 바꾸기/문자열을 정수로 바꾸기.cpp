#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    string temp;
    for(int i = 0;i<s.length();i++){
        if(s[i] == '-' || s[i] == '+')
            continue;
        
        temp += s[i];
    }
    answer = stoi(temp);
    
    if(s[0] == '-')
        answer *= -1;
    
    return answer;
}