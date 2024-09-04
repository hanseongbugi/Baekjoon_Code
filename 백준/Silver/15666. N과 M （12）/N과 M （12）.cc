#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> number;
int arr[9];

void dfs(int ptr, int cnt){
    if(cnt == M){
        for(int i = 0;i<M;i++)
            cout<<arr[i]<<' ';
        cout<<'\n';
        return;
    }
    for(int i = ptr;i<number.size();i++){
        arr[cnt] = number[i];
        dfs(i,cnt + 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>M;
    int num;
    for(int i = 0;i<N;i++){
        cin>>num;
        number.push_back(num);
    }
    sort(number.begin(), number.end());
    number.erase(unique(number.begin(),number.end()),number.end());
    dfs(0, 0);
}   