#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    // 0 1 3 5 6
    // 5 - 1
    for(int h = citations.size();h>=0;h--){
        int counter = 0;
        for(int c = 0;c<citations.size();c++){
            if(citations[c] >= h) counter++;
        }
        if(counter >= h)
            return h;
    }
    
    return 0;
}