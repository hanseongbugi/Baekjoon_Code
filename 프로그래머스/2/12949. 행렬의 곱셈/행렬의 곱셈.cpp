#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size());
    for(int i = 0;i<arr1.size();i++){
        for(int j = 0;j<arr2[0].size();j++)
            answer[i].push_back(0);
    }
    // 2*5 + 3*2 + 2*3 = 22
    // arr1[0][0] * arr2[0][0] + arr1[0][1] * arr2[1][0] + arr1[0][2] * arr2[2][0]
    
    // 2*4 + 3*4 + 2*1 = 22
    // arr1[0][0] * arr2[0][1] + arr1[0][1] * arr2[1][1] + arr1[0][2] * arr2[2][1]
    
    // arr1[0][0] * arr2[0][2] + arr1[0][1] * arr2[1][2] + arr1[0][2] * arr2[2][2]
    for(int i = 0;i<arr1.size();i++){
        for(int j = 0;j<arr1[i].size();j++){
            // 0
            int x = arr1[i][j];
            for(int k = 0;k<arr2[j].size();k++){
                int y = arr2[j][k];
                answer[i][k] += (x * y);
            }
        }
    }
    
    return answer;
}