#include <string>
#include <vector>

using namespace std;

int op1[] = {1, 2, 3, 4, 5};
int op2[] = {2, 1, 2, 3, 2, 4, 2, 5};
int op3[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
int N;
int st1, st2, st3;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    N = answers.size();
    for(int i = 0;i<N;i++){
        int num = answers[i];
        if(op1[i%5] == num)
            st1 += 1;
        if(op2[i%8] == num)
            st2 += 1;
        if(op3[i%10] == num)
            st3 += 1;
    }
    if(st1 == st2){
        if(st1 == st3){
            answer.push_back(1);
            answer.push_back(2);
            answer.push_back(3);
        }
        else if(st1 < st3){
            answer.push_back(3);
        }
        else{
            answer.push_back(1);
            answer.push_back(2);
        }
    }
    else if(st1 > st2){
        if(st3 > st1)
            answer.push_back(3);
        else if(st1 > st3)
            answer.push_back(1);
        else{
            answer.push_back(1);
            answer.push_back(3);
        }
    }
    else{
        if(st2 > st3){
            answer.push_back(2);
        }
        else if(st3 > st2){
            answer.push_back(3);
        }
        else{
            answer.push_back(2);
            answer.push_back(3);
        }
    }
    
    return answer;
}