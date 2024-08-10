#include <string>
#include <vector>
#include <iostream>
using namespace std;
char code[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };

string calc(int number, int n){
    if(number < 1)
        return "0";
    string temp = "";
    while(number >= n){
        int calcNum = number % n;
        
        if(calcNum > 9)
            temp += code[calcNum];
        else
            temp += to_string(calcNum);
        number /= n;
    }
    if(number > 0){
        if(number > 9)
            temp += code[number];
        else
            temp += to_string(number);
    }
    
    return temp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int number = 0;
    int now = 1;
    while(true){
        if(answer.length() == t)
            break;
        
        string calcNum = calc(number, n);
        while(!calcNum.empty()){
            if(answer.length() == t)
                break;
            char c = calcNum.back();
            calcNum.pop_back();
           if(now == p)
               answer += c;
            
            now++;
            if(now > m)
                now = 1;
        }
        number++;
    }
    
    return answer;
}