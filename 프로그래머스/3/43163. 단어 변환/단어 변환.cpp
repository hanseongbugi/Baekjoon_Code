#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[50];
int answer = 100;

void dfs(string begin, string target, vector<string> words, int cnt){
    for(int i = 0;i<words.size();i++){
        int counter = 0;
        
        for(int j = 0;j<words[i].length();j++){
            if(!visited[i] && begin[j] != words[i][j])
                counter++;
        }
        if(counter == 1){
            if(target == words[i] && answer > cnt + 1){
                answer = cnt + 1;
                return;
            }
            visited[i] = true;
            dfs(words[i], target, words, cnt + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    
    dfs(begin, target, words, 0);
    if(answer == 100) 
        return 0;
    return answer;
}