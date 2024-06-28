#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    
    priority_queue<int> pq;
    queue<pair<int,int>> q;
    
    for(int i = 0;i<priorities.size();i++){
        pq.push(priorities[i]);
        q.push({priorities[i],i});
    }
    
    while(!pq.empty()){
        int now = pq.top();
        pq.pop();
        while(!q.empty()){
            int process = q.front().first;
            int idx = q.front().second;
            q.pop();
            if(process != now){
                q.push({process,idx});
            }
            else{
                if(idx == location)
                    return answer;
                break;
            }
        }
        answer++;
    }
    
    return answer;
}