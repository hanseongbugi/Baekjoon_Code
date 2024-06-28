#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    for(int i = 0;i<progresses.size();i++){
        int progress = progresses[i];
        int speed = speeds[i];
        
        int range = 100 - progress;
        int day = 0;
        while(range > 0){
            range -= speed;
            day++;
        }
        q.push(day);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        int process = 1;
        while(!q.empty()){
            int to = q.front();
            if(now >= to){
                process++;
                q.pop();
            }
            else
                break;
        }
        answer.push_back(process);
    }
    return answer;
}