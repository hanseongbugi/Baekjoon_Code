#include <string>
#include <vector>

using namespace std;
int N;

vector<int> solution(vector<int> numbers) {
    N = numbers.size();
    vector<int> answer(N, -1);
    vector<int> v;
    for(int i = 0;i < N;i++){
        while(!v.empty()&&numbers[i]>numbers[v.back()]){
            answer[v.back()] = numbers[i];
            v.pop_back();
        }
        
        v.push_back(i);
    }
    return answer;
}