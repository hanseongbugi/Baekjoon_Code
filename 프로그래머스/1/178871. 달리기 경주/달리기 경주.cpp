#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    
    // player들의 등수 정보 = players 배열
    // 추월한 선수 정보 = callings 배열
    
    // 추월 = 현재 등수 1 감소, 올라간 등수의 player의 등수 1 증가
    
    // 불린 선수의 현재 등수를 알아내기
    // 현재 등수를 1 감소시킨다.
    // 감소시킨 등수를 가진 player를 찾고, 그 player의 등수를 1 증가
    
    map<string,int> play;
    map<int, string> call;
    
    for(int i = 0;i<players.size();i++){
        string player = players[i];
        
        play[player] = i + 1;
        call[i + 1] = player;
    }
    for(int i = 0;i<callings.size();i++){
        string calling = callings[i];
        
        int now = play[calling];
        string frontPlayer = call[now - 1];
        
        play[calling]--;
        play[frontPlayer]++;
        call[now - 1] = calling;
        call[now] = frontPlayer;
    }    
    for(int i = 1;i<=players.size();i++){
        answer.push_back(call[i]);
    }
    return answer;
}