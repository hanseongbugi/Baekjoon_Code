#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    
    int real_idx = phone_number.length() - 4;
    
    for(int i = 0;i<phone_number.length();i++){
        if(i >= real_idx)
            answer += phone_number[i];
        else
            answer += "*";
    }
    return answer;
}