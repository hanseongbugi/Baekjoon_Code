#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string temp = "";
    for(int i = 1;i<food.size();i++){
        int f = food[i];
        if(f > 1)
            f /= 2;
        else
            f = 0;
        
        for(int j = 0;j<f;j++)
            temp += to_string(i);
    }
    answer += temp;
    reverse(temp.begin(),temp.end());
    answer += "0";
    answer += temp;
    return answer;
}