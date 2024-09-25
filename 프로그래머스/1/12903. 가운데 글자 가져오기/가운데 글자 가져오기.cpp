#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int mid = s.length() / 2;
    if(s.length() % 2 == 0){
        answer += s[mid - 1];
        answer += s[mid]; 
    }
    else{
        answer += s[mid];
    }
    return answer;
}