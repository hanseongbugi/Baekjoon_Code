#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int now = 0, idx = 1;
    
    queue<pair<int, int>> q; // 트력 무게, 시간
    q.push({truck_weights[0], bridge_length});
    answer = 1;
    now = truck_weights[0];
    
    while(!q.empty()){
        if(q.front().second == answer){
            int qWeight = q.front().first;
            q.pop();
            now -= qWeight;
        }
        if(idx<truck_weights.size() && now + truck_weights[idx] <= weight){
            now += truck_weights[idx];
            q.push({truck_weights[idx], bridge_length + answer});
            idx++;
        }
        
        
        answer++;
    }
    
    return answer;
}