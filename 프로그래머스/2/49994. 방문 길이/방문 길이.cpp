#include <string>
#include <iostream>
using namespace std;

bool visited[11][11][4] = {false, };
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int solution(string dirs) {
    int answer = 0;
    
    int y = 5;
    int x = 5;
    
    for(int i = 0;i<dirs.length();i++){
        char c = dirs[i];
        int dir = 0;
        if(c == 'R')
            dir = 0;
        else if(c == 'U')
            dir = 1;
        else if(c == 'L')
            dir = 2;
        else
            dir = 3;
        
        int ux = x + dx[dir];
        int uy = y + dy[dir];
        
        if(ux > 10 || uy > 10 || ux < 0 || uy < 0)
            continue;
        
        int redir = (dir + 2) % 4;
        if(!visited[x][y][dir] && !visited[ux][uy][redir]){
            visited[x][y][dir] = true;
            visited[ux][uy][redir] = true;
            answer++;
        }
        y = uy;
        x = ux;
    }
    return answer;
}