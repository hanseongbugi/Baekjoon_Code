#include<iostream>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    queue<int> q;
    for(int i = 0;i<N;i++){
        string command;
        cin>>command;
        if(command =="push"){
            int input;
            cin>>input;
            q.push(input);
        }
        if(command == "pop"){
            if(q.empty()) cout<<-1<<'\n';
            else{
                int value = q.front();
                q.pop();
                cout<<value<<'\n';
            }
        }
        if(command == "size"){
            cout<<q.size()<<'\n';
        }
        if(command == "empty"){
            cout<<q.empty()<<'\n';
        }
        if(command == "front"){
            if(q.empty()) cout<<-1<<'\n';
            else{
                int value = q.front();
                cout<<value<<'\n';
            }
        }
        if(command == "back"){
            if(q.empty()) cout<<-1<<'\n';
            else{
                int value = q.back();
                cout<<value<<'\n';
            }
        }
    }
}