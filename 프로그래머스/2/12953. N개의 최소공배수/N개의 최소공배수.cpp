#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int gcd(int a, int b){
    int temp = 0;
    while(b != 0){
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int calc(int a, int b){
    return (a * b) / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = 0;
    
    sort(arr.begin(), arr.end());
    // 2와 6의 최소공배수 = 6
    // 6과 8의 최소공배수 = 24
    // 24와 14의 최소공배수 = 168
    
    int target = arr[0];
    for(int i = 1;i<arr.size();i++){
        target = calc(target, arr[i]);
    }
    answer = target;
    
    
    return answer;
}