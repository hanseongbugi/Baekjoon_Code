#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> yearn;
    for(int i = 0;i<name.size();i++){
        yearn[name[i]] = yearning[i];
    }
    for(int i = 0;i<photo.size();i++){
        int total = 0;
        for(int j = 0;j<photo[i].size();j++){
            if(yearn.find(photo[i][j])!=yearn.end())
                total += yearn[photo[i][j]];
        }
        answer.push_back(total);
    }
    return answer;
}