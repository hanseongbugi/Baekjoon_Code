#include <iostream>
#include <string>
#include <stack>
using namespace std;

int answer = 0;
string str;
stack<char> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>str;
    
    int temp = 1;
    for(int i = 0;i<str.size();i++){
        if(str[i] == '('){
            temp *= 2;
            s.push(str[i]);
        }
        else if(str[i] == '['){
            temp *= 3;
            s.push(str[i]);
        }
        
        else if(str[i] == ')'){
            if(s.empty() || s.top() != '('){
                answer = 0;
                break;
            }
            if(str[i - 1] == '('){
                answer += temp;
                temp /= 2;
                s.pop();
            }
            else{
                temp /= 2;
                s.pop();
            }
            
        }
        else if(str[i] == ']'){
            if(s.empty() || s.top() != '['){
                answer = 0;
                break;
            }
            if(str[i - 1] == '['){
                answer += temp;
                temp /= 3;
                s.pop();
            }
            else{
                temp /= 3;
                s.pop();
            }
        }
    }

    if(!s.empty())
        answer = 0;

    cout<<answer;
}
