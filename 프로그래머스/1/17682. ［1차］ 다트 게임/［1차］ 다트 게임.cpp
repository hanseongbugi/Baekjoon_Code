#include <string>
#include <vector>
using namespace std;


int solution(string dartResult) {
    int answer = 0;
    
    string num = "";
    int idx = 0;
    vector<int> result;
    
    for(int i = 0;i<dartResult.length();i++){
        char c = dartResult[i];
        if(c >= '0' && c <= '9') 
            num += c;
        
        else if(c == 'S'){
            result.push_back(stoi(num));
            num = "";
            idx++;
        }
        else if(c == 'D'){
            int n = stoi(num);
            result.push_back(n * n);
            num = "";
            idx++;
        }
        else if(c == 'T'){
            int n = stoi(num);
            result.push_back(n * n * n);
            num = "";
            idx++;
        }
        else if(c == '*'){
            if(idx == 1) 
                result[idx - 1] *= 2;
            else{
                result[idx - 2] *= 2;
                result[idx - 1] *= 2;
            }
        }
        else if(c == '#'){
            result[idx - 1] *= -1;
        }
    }
    for(int i = 0;i<result.size();i++)
        answer += result[i];
    return answer;
}