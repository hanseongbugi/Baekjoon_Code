#include <string>
#include <vector>
#include <iostream>
using namespace std;

int N;
int M = 987654321;

bool calc(string target){     
    int temp = N;

    for(int i = 0;i<target.length();i++){
        temp -= target[i] - '0';
    }
    if(temp == stoi(target))
        return true;
    else
        return false;
}
void dfs(string target){
    if(!target.empty() && calc(target)){
        M = min(M, stoi(target));
        return;
    }
    string temp = target;
    for(int i = 1;i<=9;i++){
        temp += to_string(i);
        if(temp.length()<=to_string(N).length())
            dfs(temp);
        temp.pop_back();
    }
}
int main(){
    cin>>N;
    dfs("");
    if(M == 987654321)
        M = 0;
    cout<<M<<'\n';
}