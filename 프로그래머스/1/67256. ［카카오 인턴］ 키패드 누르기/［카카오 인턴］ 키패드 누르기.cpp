#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int N;
int graph[][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -2}};
bool visited[4][3];

int dfs(int y, int x, int target){
    memset(visited, 0, sizeof(visited));
    queue<pair<pair<int,int>, int>> q;
    q.push({{y,x},0});
    visited[y][x] = true;

    while(!q.empty()){
        int qy = q.front().first.first;
        int qx = q.front().first.second;
        int counter = q.front().second;
        q.pop();
        if(graph[qy][qx] == target){
            return counter;
        }
        for(int i = 0;i<4;i++){
            int uy = dy[i] + qy;
            int ux = dx[i] + qx;
            if(uy < 0 || uy >= 4 || ux < 0 || ux >=3)
                continue;
            if(!visited[uy][ux]){
                q.push({{uy,ux}, counter+1});
                visited[uy][ux] = true;
            }
        }
    }
    return -1;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    N = numbers.size();
    
    int leftNum = -1;
    int rightNum = -2;
    for(int i = 0;i<N;i++){
        int target = numbers[i];
        if(target == 1 || target == 4 || target == 7){
            answer += "L";
            leftNum = target;
        }
        else if(target == 3 || target == 6 || target == 9){
            answer += "R";
            rightNum = target;
        }
        else{
            int leftCounter = 0;
            for(int i = 0;i<4;i++){
                for(int j = 0; j<3;j++)
                    if(graph[i][j] == leftNum)
                        leftCounter = dfs(i,j, target);
            }
            int rightCounter = 0;
            for(int i = 0;i<4;i++){
                for(int j = 0; j<3;j++)
                    if(graph[i][j] == rightNum)
                        rightCounter = dfs(i,j, target);
            }
            if(leftCounter > rightCounter){
                answer += "R";
                rightNum = target;
            }
            else if(leftCounter < rightCounter){
                answer += "L";
                leftNum = target;
            }
            else{
                if(hand == "right"){
                    answer += "R";
                    rightNum = target;
                }
                else{
                    answer += "L";
                    leftNum = target;
                }
            }
        }
    }
    return answer;
}
