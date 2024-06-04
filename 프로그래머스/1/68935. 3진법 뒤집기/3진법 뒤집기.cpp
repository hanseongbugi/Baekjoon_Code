#include <string>
#include <vector>

using namespace std;

vector<int> number;
void makeNumber(int n){
    if(n < 3){
        number.push_back(n);
        return;
    }
    while(n >= 3){
        number.push_back(n%3);
        n /= 3;
    }
    number.push_back(n);
}

int solution(int n) {
    int answer = 0;

    makeNumber(n);
    answer = number[number.size() - 1];
    int key = 1;
    for(int i = number.size() - 2;i>=0;i--){
        int temp = 1;
        for(int j = 0;j < key;j++){
            temp *= 3;
        }
        answer += number[i] * temp; 
        key++;
    }
    return answer;
}