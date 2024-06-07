#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int N = absolutes.size();
    for(int i = 0;i<N;i++){
        int num = absolutes[i];
        if(!signs[i])
            num *= -1;
        answer += num;
    }
    return answer;
}