#include <string>
#include <vector>

using namespace std;
int N;
string solution(string s) {
    string answer = "";
    N = s.length();
    int cnt = 0;
    for(int i = 0;i<N; i++){
        if(s[i] == ' '){
            cnt = 0;
            answer += s[i];
            continue;
        }
        
        if(cnt % 2 == 0){
            if(s[i]>='a')
                answer += s[i] - 32;
            else
                answer += s[i];
        }
        else{
            if(s[i]<'a')
                answer += s[i] + 32;
            else
                answer += s[i];
        }
        cnt++;
    }
    return answer;
}