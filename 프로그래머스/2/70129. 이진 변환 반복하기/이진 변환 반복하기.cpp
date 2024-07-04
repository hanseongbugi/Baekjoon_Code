#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string makeBinary(int n){
    if(n < 2)
        return "1";
    
    string temp = "";
    // 6 3...0
    // 3 1...1
    // 1 
    while(n > 0){
        temp += to_string(n%2);
        n/=2;
    }
    reverse(temp.begin(),temp.end());
    return temp;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int zeroCount = 0;
    int oneCount = 0;
    int counter = 0;
    while(s!="1"){
        zeroCount += count(s.begin(),s.end(),'0');
        oneCount = count(s.begin(),s.end(),'1');
        s = makeBinary(oneCount);
        counter++;
    }
    // 111111  000000
    // 11      0
    // 1       0
    answer.push_back(counter);
    answer.push_back(zeroCount);
    return answer;
}