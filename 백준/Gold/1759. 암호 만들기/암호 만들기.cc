#include <iostream>
#include <algorithm>
using namespace std;

int L, C;
char alpha[16];
char answer[16];
int visited[16];

void dfs(int idx, int moCnt, int jaCnt, int depth){
    if(depth == L && moCnt >= 1 && jaCnt >= 2){
        for(int i = 0;i<L;i++){
            cout<<answer[i];
        }
        cout<<'\n';
        return;
    }
    for(int i = idx;i<C;i++){
        if(!visited[i]){
            visited[i] = true;
            answer[depth] = alpha[i];
            if(alpha[i] == 'a' ||alpha[i] == 'e'||alpha[i] == 'i'||alpha[i] == 'o'||alpha[i] == 'u'){
                dfs(i + 1, moCnt + 1, jaCnt, depth + 1);
            }
            else{
                dfs(i + 1,moCnt, jaCnt + 1, depth + 1);
            }
           
            visited[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>L>>C;

    for(int i = 0;i<C;i++)
        cin>>alpha[i];
    sort(alpha, alpha + C);
    dfs(0, 0, 0, 0);
}   