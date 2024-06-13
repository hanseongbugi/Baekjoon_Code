#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
queue<string> c1, c2, g;

void copyQueue(vector<string>& v, queue<string>& q){
    for(int i = 0;i<v.size();i++)
        q.push(v[i]);
}

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    // 선입선출을 위한 큐로의 복사
    copyQueue(cards1,c1);
    copyQueue(cards2,c2);
    
    for(int i = 0;i<goal.size();i++){
        string target = goal[i];
        if(c1.front()==target){
            c1.pop();
        }
        else if(c2.front()==target){
            c2.pop();
        }
        else{
            return "No";
        }
    }
    
    

    return "Yes";
}