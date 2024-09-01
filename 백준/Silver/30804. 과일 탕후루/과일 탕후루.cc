#include <iostream>
#include <queue>
using namespace std;

int N;
int cnt[10], other = 0, answer = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;
    queue<int> q;
    int fruit;
    for(int i = 0;i<N;i++){
        cin>>fruit;
        q.push(fruit);

        if(cnt[fruit]++ == 0){
            other++;
        }
        while(other > 2){
            fruit = q.front();
            q.pop();
            cnt[fruit]--;
            if(cnt[fruit] == 0){
                other--;
            }
        }
        answer = max(answer, static_cast<int>(q.size()));
    }
    cout<<answer;
}