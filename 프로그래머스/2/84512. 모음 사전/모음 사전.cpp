#include <string>
#include <vector>

using namespace std;

string alpha = "AEIOU";
int answer = -1;
int count = 0;

void dfs(string target, string word){
    if(answer == count)
        return;
    
    for(int i = 0;i<5;i++){
        target += alpha[i];
        count++;
        if(target == word){
            answer = count;
            return;
        }
        if(target.length() < 5){
            dfs(target, word);
        }
        target.pop_back();
    }
}
int solution(string word) {
    answer = -1;
    count = 0;
    
    dfs("",word);
    return answer;
}