#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    
    long long div = 10;
    while(n != 0){
        answer.push_back(n % div);
        
        n /= div;
    }
    
    return answer;
}