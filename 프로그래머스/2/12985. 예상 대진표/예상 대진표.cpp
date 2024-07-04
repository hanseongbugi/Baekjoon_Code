#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;
 
    
    while(abs(a-b)!=1||a/2==b/2){
        if(a%2==0)
            a/=2;
        else{
            a++;
            a/=2;
        }
        if(b%2==0)
            b/=2;
        else{
            b++;
            b/=2;
        }
        answer++;  
    }

    return answer;
}