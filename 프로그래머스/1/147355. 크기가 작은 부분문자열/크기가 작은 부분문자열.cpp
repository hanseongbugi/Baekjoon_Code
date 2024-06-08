#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;

    int ptr = p.length();
    for(int i = 0;i <= t.length() - ptr;i++){
        string num = string(t.begin() + i, t.begin() + i + ptr);
        if(p >= num){
            answer++;
        }
    }
    return answer;
}