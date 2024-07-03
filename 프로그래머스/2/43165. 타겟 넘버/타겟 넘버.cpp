#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int answer = 0;

void dfs(int n, int idx, vector<int> numbers, int target){
    if(idx >= numbers.size()) {
        if(n == target){
            answer++;
        }
        return;
    }
    dfs(n + (-1 * numbers[idx]), idx + 1, numbers, target);
    dfs(n + numbers[idx], idx + 1, numbers, target);
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    
    // -1 1
    dfs(-1 * numbers[0], 1, numbers, target);
    dfs(numbers[0], 1, numbers, target);
    // -1+1 -1-1 | 1+1 1-1
    // -1+1-1 -1-1-1 1+1-1 1-1-1 | -1+1+1 -1-1+1 1+1+1 1-1+1
    return answer;
}