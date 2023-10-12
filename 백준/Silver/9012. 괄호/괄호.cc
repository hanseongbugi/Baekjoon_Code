#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    for(int i = 0;i<N;i++){
        string input;
        cin>>input;
        vector<char> stack;
        for(int j = 0;j<input.length();j++)
            stack.push_back(input[j]);
        
        bool check = false;
        vector<bool> counter;
        while(!stack.empty()){
            char c = stack.back();
            stack.pop_back();
            if(c == ')'){
                counter.push_back(true);
            }
            if(c == '(') {
                if(counter.empty()){ 
                    check = false;
                    break;
                }
                check = true;
                counter.pop_back();
            }
        }
        if(check&&counter.empty()) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
}