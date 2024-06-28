#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i = 0;i<scoville.size();i++)
        q.push(scoville[i]);
    
    while(!q.empty()){
        int food1 = q.top();
        q.pop();
        if(food1 < K){
            if(q.empty())
                return -1;
            
            int food2 = q.top();
            q.pop();
            q.push(food1 + (food2 * 2));
            answer++;
        }
        else{
            break;
        }
    }

    return answer;
}