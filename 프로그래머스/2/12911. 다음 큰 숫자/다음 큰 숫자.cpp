#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int calc(int n){
    int cnt=0;
    
    while(n!=0){
        if(n%2==1) cnt++;
        n/=2;
    }
    
    return cnt;
}


int solution(int n) {
    int answer = 0;
    int temp = calc(n);
    n++;
    
    while(calc(n)!=temp){
        n++;
    }
    
    answer = n;
    return answer;
}