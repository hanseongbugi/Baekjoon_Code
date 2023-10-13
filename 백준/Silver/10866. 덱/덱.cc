#include<iostream>
#include<deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    deque<int> dq;
    for(int i = 0;i<N;i++){
        string command;
        cin>>command;
        if(command =="push_front"){
            int input;
            cin>>input;
            dq.push_front(input);
        }
        if(command =="push_back"){
            int input;
            cin>>input;
            dq.push_back(input);
        }
        if(command == "pop_front"){
            if(dq.empty()) cout<<-1<<'\n';
            else{
                int value = dq.front();
                dq.pop_front();
                cout<<value<<'\n';
            }
        }
        if(command == "pop_back"){
            if(dq.empty()) cout<<-1<<'\n';
            else{
                int value = dq.back();
                dq.pop_back();
                cout<<value<<'\n';
            }
        }
        if(command == "size"){
            cout<<dq.size()<<'\n';
        }
        if(command == "empty"){
            cout<<dq.empty()<<'\n';
        }
        if(command == "front"){
            if(dq.empty()) cout<<-1<<'\n';
            else{
                int value = dq.front();
                cout<<value<<'\n';
            }
        }
        if(command == "back"){
            if(dq.empty()) cout<<-1<<'\n';
            else{
                int value = dq.back();
                cout<<value<<'\n';
            }
        }
    }
}