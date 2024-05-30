#include <string>
#include <vector>

using namespace std;
vector<int> barket;
int N,M;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    N = board.size();
    M = moves.size();
    for(int i = 0;i<M;i++){
        int crane = 0;
        int move = moves[i];
        while(crane < N){
            if(board[crane][move-1]>0){
                if(!barket.empty()&&barket.back() == board[crane][move-1]){
                    answer += 2;
                    barket.pop_back();
                }
                else
                    barket.push_back(board[crane][move-1]);
                board[crane][move-1] = 0;
                break;
            }
            crane += 1;
        }
        
    }
    
    return answer;
}