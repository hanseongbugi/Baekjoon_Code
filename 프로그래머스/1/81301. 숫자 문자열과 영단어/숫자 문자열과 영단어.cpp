#include <string>
#include <vector>
#include <map>
using namespace std;
map<string,string> m = {{"zero","0"},{"one","1"},{"two","2"},{"three","3"},{"four","4"},{"five","5"},{"six","6"},{"seven","7"},{"eight","8"},{"nine","9"}};

int solution(string s) {
    int answer = 0;
    
    string number = "";
    string str = "";
    for(int i = 0;i<s.length();i++){
        char c = s[i];
        if(c >= '0' && c <='9'){
            number += c;
            str = "";
        }
        else{
            str += c;
            if(m.find(str) != m.end()){
                number += m[str];
                str = "";
            }
        }
    }
    answer = stoi(number);
    return answer;
}