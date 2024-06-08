#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char x = s[0];
    string temp = "";
    int counter = 1;
    int counter2 = 0;
    
    for(int i = 1;i<s.length();i++){
        temp += s[i];
        
        if(x == s[i])
            counter++;
        else{
            counter2++;
            if(counter == counter2){
                x = s[++i];
                counter = 1;
                counter2 = 0;
                temp = "";
                answer++;
            }
        }
    }
    if(!temp.empty() || x == s[s.length() - 1])
        answer++;
    return answer;
}