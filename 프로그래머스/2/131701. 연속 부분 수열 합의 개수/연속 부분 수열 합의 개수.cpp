#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    vector<int> v;
    int start = 0, end = 0;
    
    for(int i = 0;i<elements.size();i++){
        int sum = 0;
        for(int j = i;j<i+elements.size();j++){
            int idx = j % elements.size();
            sum += elements[idx];
            v.push_back(sum);
        }
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    answer = v.size();
    return answer;
}