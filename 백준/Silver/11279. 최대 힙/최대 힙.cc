#include <iostream>
#include <queue>
using namespace std;

int N;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin>>N;
    int num;
    priority_queue<int> q;
    for(int i = 0;i<N;i++){
        cin>>num;

        if(num == 0){
            if(q.empty())
                cout<<0<<'\n';
            else{
                cout<<q.top()<<'\n';
                q.pop();
            }
        }
        else{
            q.push(num);
        }
    }
}