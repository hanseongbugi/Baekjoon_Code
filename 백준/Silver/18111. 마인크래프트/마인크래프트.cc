#include <iostream>
#include <cmath>
using namespace std;

int N, M, B;
int arr[501][501];
int minBlock = 257, maxBlock = 0;
int answer = 987654321, height = -1;

void dfs(int h, int b){
    int t = 0;

    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(arr[i][j] > h){
                b += arr[i][j] - h;
                t += 2 * (arr[i][j] - h);
            }
        }
    }
    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            if(arr[i][j] < h){
                b -= h - arr[i][j];
                t += 1 * (h - arr[i][j]);
            }
        }
    }
    if(b >= 0){
        answer = min(answer, t);
        if(answer == t)
            height = max(height, h);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin>>N>>M>>B;

    for(int i = 0;i<N;i++){
        for(int j = 0;j<M;j++){
            cin>>arr[i][j];
            minBlock = min(arr[i][j], minBlock);
            maxBlock = max(arr[i][j], maxBlock);
        }
    }
    for(int i = minBlock; i<=maxBlock;i++)
        dfs(i,B);

    cout<<answer<<' '<<height<<'\n';
}