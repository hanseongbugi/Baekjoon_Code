#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0;i<prices.size();i++){
        int counter = 0;
        int price = prices[i];
        for(int j = i + 1;j < prices.size();j++){
            counter++;
            if(price > prices[j])
                break;
        }
        answer.push_back(counter);
    }
    return answer;
}