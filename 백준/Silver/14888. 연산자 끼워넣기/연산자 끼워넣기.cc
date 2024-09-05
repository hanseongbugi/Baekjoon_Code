#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int A[101];
int opt[4];
int maxNum = -1000000000;
int minNum = 1000000000;

void dfs(int sum, int cnt){
    if(cnt == N){
        maxNum = max(maxNum, sum);
        minNum = min(minNum, sum);
        return;
    }
    int num = A[cnt];
    if(opt[0] > 0){
        opt[0]--;
        dfs(sum + num, cnt + 1);
        opt[0]++;
    }
    if(opt[1] > 0){
        opt[1]--;
        dfs(sum - num, cnt + 1);
        opt[1]++;
    }
    if(opt[2] > 0){
        opt[2]--;
        dfs(sum * num, cnt + 1);
        opt[2]++;
    }
    if(opt[3] > 0){
        opt[3]--;
        dfs(sum / num, cnt + 1);
        opt[3]++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>A[i];
    
    for(int i = 0;i<4;i++)
        cin>>opt[i];

    dfs(A[0],1);
    cout<<maxNum<<'\n'<<minNum;
}   