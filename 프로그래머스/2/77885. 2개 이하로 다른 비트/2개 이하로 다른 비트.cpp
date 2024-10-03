#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long f(long long x){
    // 짝수의 경우 n + 1
    // 2 -> 3, 4 -> 5
    if(x % 2 == 0){
        return x + 1;
    }
    // 홀수의 경우
    // 올림을 해서 최소 2개의 비트가 바뀌게 해준다.
    long long bit = 1;
    while(true){
        if((x & bit) == 0)
            break;
        bit *= 2; // 곱하기 2를 통해 다음 비트로 이동
    }
    bit /= 2;
    return x + bit;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i = 0;i<numbers.size();i++){
        long long x = numbers[i];
        answer.push_back(f(x));
    }
    return answer;
}