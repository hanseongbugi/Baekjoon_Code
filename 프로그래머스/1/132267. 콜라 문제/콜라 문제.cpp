#include <string>
#include <vector>

using namespace std;
int x, result;
int solution(int a, int b, int n) {
    int answer = 0;
    
    // n / a = x
    // result = n - (x * a) + x = 20 - (6 * 3) + 6 = 8
    // result / a = x2 = 8 / 3 = 2
    // result = result - (x2 * a) + x2 = 8 - (2 * 3) + 2 = 4
    
    // 4 / 3 = 1
    // 4 - (1 * 3) + 1 = 2 
    result = n;
    while(result >= a){
        x = result / a;
        result %= a;
        result += b * x;
        answer += x * b;
    }
    
    return answer;
}