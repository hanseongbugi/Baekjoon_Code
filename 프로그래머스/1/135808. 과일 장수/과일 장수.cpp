#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end());
    vector<int> box;
    
    for(int i = score.size() - 1;i>=0;i--){
        int apple = score[i];
        if(apple <= k){
            box.push_back(apple);
        }
        if(box.size() == m){
            int minScore = 11;
            for(int j = 0;j<box.size();j++){
                minScore = min(box[j],minScore);
            }
            
            answer += minScore * m;
            while(!box.empty())
                box.pop_back();
        }
    }
    
    return answer;
}