#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    for(int i = 0;i<s.length();i++){
        char c = s[i];
        int skipNum = 0;
        for(int j = 1;j<=index + skipNum;j++){
            c++;
            if(c > 'z')
                c = 'a';
            bool isSkip = false;
            for(int k = 0;k<skip.length();k++){
                if(c == skip[k]){
                    isSkip = true;
                }
            }
            if(isSkip){
                skipNum++;
                continue;
            }
        }
        answer += c;
    }
    return answer;
}