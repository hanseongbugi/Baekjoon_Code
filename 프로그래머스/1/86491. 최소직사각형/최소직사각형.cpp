#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    // 50 30 30 40 
    // 60 70 60 80
    
    // 7  3  8  7  5
    // 10 12 15 14 15
    
    // 4  6  6  7  7
    // 14 19 16 18 11
    int w = 0;
    int h = 0;
    
    for(int i = 0;i<sizes.size();i++){
        int dw = sizes[i][0];
        int dh = sizes[i][1];
        if(dw > dh){
            w = max(w,dh);
            h = max(h,dw);
        }
        else{
            w = max(w,dw);
            h = max(h,dh);
        }
    }
    answer = w * h;
    return answer;
}