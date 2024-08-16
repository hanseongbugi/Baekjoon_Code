#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int arr[129][129];
int white = 0;
int blue = 0;
void dfs(int y, int x, int cnt){
    bool cut = false;

    int color = arr[y][x];

    for(int i = y;i<y + cnt; i++){
        for(int j = x; j<x + cnt; j++){
            if(arr[i][j] != color){
                cut = true;
                break;
            }
        }
    }
    if(cut){
        dfs(y, x, cnt/2);
        dfs(y, x + cnt / 2, cnt/2);
        dfs(y + cnt / 2, x, cnt/ 2);
        dfs(y + cnt / 2, x + cnt / 2, cnt / 2);
    }
    else{
        if(color == 1)
            blue++;
        else
            white++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N;
    
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++)
            cin>>arr[i][j];
    }

    dfs(0, 0, N);

    cout<<white<<'\n';
    cout<<blue<<'\n';
}