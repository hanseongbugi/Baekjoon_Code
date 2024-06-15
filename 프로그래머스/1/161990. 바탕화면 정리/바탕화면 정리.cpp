#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int lux = 100, luy = 100, rdx = 0, rdy = 0;
    for(int i = 0;i<wallpaper.size();i++){
        for(int j = 0;j<wallpaper[i].length();j++){
            if(wallpaper[i][j] == '#'){
                lux = min(i,lux);
                luy = min(j,luy);
                rdx = max(i,rdx);
                rdy = max(j,rdy);
            }
        }
    }
    answer.push_back(lux);
    answer.push_back(luy);
    answer.push_back(rdx + 1);
    answer.push_back(rdy + 1);
    return answer;
}