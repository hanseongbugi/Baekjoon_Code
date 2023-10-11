#include<iostream>
#include<queue>
using namespace std;

int main(){
    int N;
    cin>>N;
    queue<int> q;
    for(int i = 1; i<=N; i++)
        q.push(i);
    
    bool trash = true;
    while(q.size() != 1){
        if(trash){
            q.pop();
            trash = false;
        }else{
            int card = q.front();
            q.pop();
            q.push(card);
            trash = true;
        }
    }
    cout<<q.front()<<'\n';
}