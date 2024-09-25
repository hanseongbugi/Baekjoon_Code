#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    long long calc = sqrt(n);
    
    if(calc * calc != n)
        answer = -1;
    else
        answer = (calc + 1) * (calc + 1);
    return answer;
}