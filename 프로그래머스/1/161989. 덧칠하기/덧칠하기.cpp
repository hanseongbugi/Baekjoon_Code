#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int now = 0;
    for(int i = 0;i<section.size();i++){
        if(now >= section[i])
            continue;
        now = section[i] + m - 1; 
        answer++;
    }
    return answer;
}