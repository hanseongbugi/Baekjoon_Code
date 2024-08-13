#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

string calc(int n, int k){
    
    string temp = "";
    while(n >= k){
        temp += to_string(n % k);
        n /= k;
    }
    if(n > 0)
        temp += to_string(n);
    
    reverse(temp.begin(),temp.end());
    return temp;
}
bool isPrime(string str){
    long long num = stoll(str);
    
    if(num < 2) return false;
        
    for(int i=2; i<=sqrt(num); i++) {
        if(num % i == 0) 
            return false;
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    
    string calcNum = calc(n, k);
    string temp = "";
    for(int i = 0;i<calcNum.length();i++){
        char c = calcNum[i];
        if(c == '0'){
            if(!temp.empty()&&isPrime(temp)){
                answer++;
            }
            temp = "";
        }
        else
            temp += c;
    }
    if(!temp.empty()&&isPrime(temp))
        answer++;
    
    return answer;
}