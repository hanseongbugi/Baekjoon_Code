#include <string>
#include <vector>

using namespace std;

bool visited[8] = {false, };
int answer = 0;

void dfs(int k, int cnt, vector<vector<int>> dungeons){
    answer = max(answer, cnt);
    for(int i = 0;i<dungeons.size(); i++){
        if(visited[i] == false && k >= dungeons[i][0]){
            visited[i] = true;
            dfs(k - dungeons[i][1] ,cnt + 1, dungeons);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    answer = 0;
    
    dfs(k,0,dungeons);
    return answer;
}