#include <vector>
#include <iostream>
using namespace std;

bool check(int n) {
    if(n < 2) return false;
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0, sum;
    
    for(int i = 0; i < nums.size(); ++i) {
        for(int j = i + 1; j < nums.size(); ++j) {
            for(int z = j + 1; z < nums.size(); ++z) {
                sum = nums[i] + nums[j] + nums[z];
                if(check(sum)) answer++;
            }
        }
    }
    return answer;
}