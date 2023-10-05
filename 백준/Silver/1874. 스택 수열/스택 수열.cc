#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> stack;
    int top = -1;
    int item = 1;
    vector<char> buffer;
    for(int i = 0;i<N;i++){
        int target;
        cin>>target;
        while(true){
            if(!stack.empty()){
                if(stack[top]==target){
                    break;
                }
            }
            buffer.push_back('+');
            stack.push_back(item);
            top +=1;
            item += 1;
            if(top>N){
                cout<<"NO"<<'\n';
                return 0;
            }
        }
        if(stack[top]==target) {
            buffer.push_back('-');
            stack.pop_back();
            top -= 1;
        }
    }
    for(int i =0;i<buffer.size();i++)
        cout<<buffer[i]<<'\n';
}