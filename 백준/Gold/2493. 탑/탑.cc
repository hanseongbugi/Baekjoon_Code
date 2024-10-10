#include <iostream>
#include <stack>
using namespace std;

int N;
int tops[500001];
stack<pair<int,int>> s;
int answer[500001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    
    for(int i = 0;i<N;i++)
        cin>>tops[i];
    
    // 6 9 5 7 4
    // 주어진 순서의 반대 방향으로 신호 발사
    for(int i = 0;i<N;i++){
        while(!s.empty() && s.top().first <= tops[i])
            s.pop();
        
        if(s.empty())
            answer[i] = 0;
        else
            answer[i] = s.top().second;
        
        s.push({tops[i],i + 1});
    }
    
    for(int i = 0;i<N;i++)
        cout<<answer[i]<<' ';

}
