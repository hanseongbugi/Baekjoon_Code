#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> v(10000001);
    
    for(int i = 0;i<tangerine.size();i++)
        v[tangerine[i]]++;
    
    sort(v.begin(),v.end(),greater<int>());
    int i = 0;
    while(k > 0){
        k -= v[i];
        i++;
        answer++;
    }
    
    return answer;
}