#include <string>
#include <vector>

using namespace std;

int op1[] = {1, 2, 3, 4, 5};
int op2[] = {2, 1, 2, 3, 2, 4, 2, 5};
int op3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int N;
int st[3];

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    N = answers.size();
    for(int i = 0;i<N;i++){
        int num = answers[i];
        if(op1[i%5] == num)
            st[0] += 1;
        if(op2[i%8] == num)
            st[1] += 1;
        if(op3[i%10] == num)
            st[2] += 1;
    }
    int maxNum = max(max(st[0], st[1]), st[2]);
    
    for(int i = 0;i<3;i++){
        if(maxNum == st[i]) 
            answer.push_back(i+1);
    }
    
    return answer;
}
