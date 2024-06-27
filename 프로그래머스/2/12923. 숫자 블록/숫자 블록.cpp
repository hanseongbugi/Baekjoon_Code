#include <string>
#include <vector>
#include <cmath>
using namespace std;

int isPrime(int n) {
    if (n < 2) return 0;

    int max = 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            max = i;
            if (n / i <= 10000000) return n / i;

        }
    }

    if (!max) return 1; // 소수
    else return max;
}

vector<int> solution(long long begin, long long end) {
    vector<int> answer;
    for (long long i = begin; i <= end; i++) {
        answer.push_back(isPrime(i));
    }
    return answer;
}