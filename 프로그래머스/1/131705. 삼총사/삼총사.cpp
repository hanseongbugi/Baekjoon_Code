#include <string>
#include <vector>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    // -5 -2 0 2 3
    for(int i = 0;i<number.size();i++){
        int p1 = number[i];
        for(int j = i + 1;j<number.size();j++){
            int p2 = number[j];
            for(int k = j + 1;k<number.size();k++){
                int p3 = number[k];
                if(p1 + p2 + p3 == 0)
                    answer++;
            }
        }
    }
    return answer;
}