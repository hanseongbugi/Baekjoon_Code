#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    if(num == 1){
        return 0;
    }
    
    long long temp = num;
    while(temp != 1){
        if(answer >= 500)
            break;
        
        if(temp % 2 == 0){
            temp /= 2;
        }
        else{
            temp *= 3;
            temp += 1;
        }
        answer++;
    }
    if(answer >= 500)
        answer = -1;
    
    return answer;
}