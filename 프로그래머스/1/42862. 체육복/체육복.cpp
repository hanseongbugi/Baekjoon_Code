#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int st[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(int i = 0;i<lost.size();i++){
        st[lost[i]]--; 
    }
    for(int i = 0;i<reserve.size();i++){
        st[reserve[i]]++; 
    }
    
    for(int i = 1; i <= n; i++){
        if(st[i] == -1){
            if(st[i - 1] == 1){
                st[i - 1] = 0;
                st[i] = 0;
            }
            else if(st[i + 1] == 1){
                st[i + 1] = 0;
                st[i] = 0;
            }
        }   
            
        if(st[i] >= 0) answer++;
    }
    return answer;
}