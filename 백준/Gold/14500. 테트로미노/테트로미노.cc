#include <iostream>
#include <cstring>
using namespace std;

int N,M;
int graph[500][500];
int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0}};
bool visited[500][500];
int answer;

bool isInside(int r, int c){
    if(r<0||r>=N||c<0||c>=M)return false;
    return true;
}
void dfs(int r, int c, int depth, int sum){
    if(depth == 3){
        answer = max(answer, sum);
        return;
    }
    for(int i = 0;i<4;i++){
        int dR = r + dir[i][0];
        int dC = c + dir[i][1];
        if(!isInside(dR,dC))continue;;
        if(visited[dR][dC])continue;
        visited[dR][dC] = true;
        dfs(dR,dC,depth + 1, sum + graph[dR][dC]);
        visited[dR][dC] = false;
    }
}
void shape1(int r, int c)
{
	int sum = 0;
	sum = graph[r][c] + graph[r][c + 1] + graph[r][c + 2] + graph[r - 1][c + 1];
	answer = max(answer, sum);
}

void shape2(int r, int c)
{
	int sum = 0;
	sum = graph[r][c] + graph[r][c + 1] + graph[r][c + 2] + graph[r + 1][c + 1];
	answer = max(answer, sum);
}

void shape3(int r, int c)
{
	int sum = 0;
	sum = graph[r][c] + graph[r + 1][c] + graph[r + 2][c] + graph[r + 1][c + 1];
	answer = max(answer, sum);
}

void shape4(int r, int c)
{
	int sum = 0;
	sum = graph[r][c] + graph[r - 1][c + 1] + graph[r][c + 1] + graph[r + 1][c + 1];
	answer = max(answer, sum);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    answer = 0;
    cin>>N>>M;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++)
            cin>>graph[i][j];
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            visited[i][j] = true;
            dfs(i,j,0,graph[i][j]);
            visited[i][j] = false;
            if (i - 1 >= 0 && j + 2 < M) shape1(i, j);
			if (j + 2 < M && i + 1 < N) shape2(i, j);
			if (i + 2 < N && j + 1 < M) shape3(i, j);
			if (i + 1 < N && i - 1 >= 0 && j + 1 < M) shape4(i, j);
        }
    }
    cout<<answer;
}