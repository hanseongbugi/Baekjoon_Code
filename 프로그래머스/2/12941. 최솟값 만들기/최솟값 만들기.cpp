#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int calc(vector<int> v1, vector<int> v2){
    int answer = 0;
    for(int i = 0;i<v1.size();i++){
        answer += v1[i] * v2.back();
        v2.pop_back();
    }
    return answer;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    if(A[0] > B[0]){
        answer = calc(B,A);
    }
    else{
        answer = calc(A,B);
    }


    return answer;
}