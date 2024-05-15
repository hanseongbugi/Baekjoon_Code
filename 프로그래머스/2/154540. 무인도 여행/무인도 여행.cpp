#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arr[101][101] = {0, };
bool visited[101][101] = {0, };
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int maxY, maxX;

void dfs(int y, int x, int& result){
    visited[y][x] = 1;
    result += arr[y][x];
    
    for(int i = 0;i<4;i++){
        int uy = y + dy[i];
        int ux = x + dx[i];
        if(uy<0||uy>=maxY||ux<0||ux>=maxX) continue;
        if(arr[uy][ux]){
            if(!visited[uy][ux])
                dfs(uy,ux,result);
        }
    }
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for(int i = 0;i<maps.size(); i++){
        string target = maps[i];
        for(int j = 0;j<target.length();j++){
            if(target[j] == 'X')
                arr[i][j] = 0;
            else
                arr[i][j] = target[j] - '0';
        }
    }
    maxY = maps.size();
    maxX = maps[0].length();
    

    for(int i = 0; i<maxY;i++){
        for(int j = 0;j<maxX;j++){
            int remain = 0;
            if(arr[i][j] != 0){
                if(!visited[i][j]){
                    dfs(i,j, remain);
                    answer.push_back(remain);
                }
            }
        }
    }
    if(answer.empty()){
        answer.push_back(-1);
    }
    sort(answer.begin(), answer.end());
    return answer;
}