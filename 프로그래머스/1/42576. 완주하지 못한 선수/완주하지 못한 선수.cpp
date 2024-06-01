#include <string>
#include <vector>
#include <map>
using namespace std;

int N, M;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string,int> m;
    N = completion.size();
    M = participant.size();
    
    for(int i = 0;i<N;i++){
        string name = completion[i];
        if(m[name] > 0)
            m[name] += 1;
        else{
            m[name] = 1;
        }
    }
    for(int i = 0;i<M;i++){
        string name = participant[i];
        if(m[name] < 1){
            answer += name;
        }
        else{
            m[name]--;
        }
    }

    return answer;
}