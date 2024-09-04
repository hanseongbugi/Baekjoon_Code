#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int number[9];
int arr[9];
bool visited[9];

void dfs(int num, int cnt){
    if(cnt == M){
        for(int i = 0;i<M;i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i = num;i<=N;i++){
        int n = number[i - 1];
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = n;
            dfs(i + 1,cnt + 1);
            visited[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    for(int i = 0;i<N;i++)
        cin>>number[i];
    sort(number, number + N);

    dfs(1, 0);
}   