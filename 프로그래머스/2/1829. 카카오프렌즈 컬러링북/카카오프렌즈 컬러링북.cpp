#include <vector>
#include <queue>
using namespace std;

int M, N;
bool visited[101][101] = {false, };
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};
int number_of_area = 0;
int max_size_of_one_area = 0;

void bfs(int y,int x, int level, vector<vector<int>> picture){
    queue<pair<int,int>> q;
    
    q.push({y,x});
    visited[y][x] = true;
    int counter = 0;
    while(!q.empty()){
        int qy = q.front().first;
        int qx = q.front().second;
        q.pop();
        counter++;
        for(int i = 0;i<4;i++){
            int uy = qy + dy[i];
            int ux = qx + dx[i];
            if(uy < 0 || uy >= M || ux < 0 || ux >= N)
                continue;
            if(picture[uy][ux] != level)
                continue;
            
            if(!visited[uy][ux]){
                q.push({uy,ux});
                visited[uy][ux] = true;
            }
        }
    }
    max_size_of_one_area = max(max_size_of_one_area, counter);
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    number_of_area = 0;
    max_size_of_one_area = 0;
    
    M = m;
    N = n;
    for(int i = 0;i<101;i++){
        for(int j = 0;j<101;j++)
            visited[i][j] = false;
    }
    dy[0] = -1; dx[0] = 0;
    dy[1] = 1; dx[1] = 0;
    dy[2] = 0; dx[2] = 1;
    dy[3] = 0; dx[3] = -1;
    
    for(int i = 0;i<M;i++){
        for(int j = 0;j<N;j++){
            if(!visited[i][j]&&picture[i][j] != 0){
                bfs(i,j, picture[i][j], picture);
                number_of_area++;
            }
        }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}