#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> stack;
    for(int i = 0;i<N;i++){
        string command;
        cin>>command;
        if(command =="push"){
            int input;
            cin>>input;
            stack.push_back(input);
        }
        if(command == "pop"){
            if(stack.empty()) cout<<-1<<'\n';
            else{
                int value = stack.back();
                stack.pop_back();
                cout<<value<<'\n';
            }
        }
        if(command == "size"){
            cout<<stack.size()<<'\n';
        }
        if(command == "empty"){
            cout<<stack.empty()<<'\n';
        }
        if(command == "top"){
            if(stack.empty()) cout<<-1<<'\n';
            else{
                int value = stack.back();
                cout<<value<<'\n';
            }
        }
    }
}