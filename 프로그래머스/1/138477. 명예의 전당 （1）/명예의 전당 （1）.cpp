#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int,vector<int>,greater<int>> ranking;
    
    for(int i = 0;i<score.size();i++){
        if(ranking.size() == k){
            int third = ranking.top();
            if(third < score[i]){
                ranking.pop();
                ranking.push(score[i]);
            }
        }else{
            ranking.push(score[i]);
        }
        answer.push_back(ranking.top());
    }
    return answer;
}