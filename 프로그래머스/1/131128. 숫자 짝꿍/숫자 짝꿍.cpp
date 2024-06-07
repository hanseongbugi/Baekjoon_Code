#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<char> v;

    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    // 0 0 1
    // 2 3 4 5
    
    // 0 0 1
    // 0 0 2 3 4 5
    
    // 0 0 1
    // 0 1 2 3 4 5
    
    // 1 1 2 2 3
    // 1 2 3 4 5
    char dx, dy;
    while(!X.empty()&&!Y.empty()){
        dx = X.back();
        dy = Y.back();
        
        if(dx == dy){
            v.push_back(dx);
            X.pop_back();
            Y.pop_back();
        }
        else{
            if(dx > dy)
                X.pop_back();
            else
                Y.pop_back();
        }
    }
    if(v.empty())
        return "-1";
    
    sort(v.begin(),v.end());
    if(v[v.size() - 1] == '0')
        return "0";
    
    for(int i = v.size() - 1;i>=0;i--)
        answer += v[i];
    
    return answer;
}