#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    
    for(int i = 3;i<=total;i++){
        if(total % i == 0){
            int num = total/i;
            
            if((i - 2) * (num - 2) == yellow){
                answer.push_back(num);
                answer.push_back(i);
                break;
            }
        }
    }
    return answer;
}