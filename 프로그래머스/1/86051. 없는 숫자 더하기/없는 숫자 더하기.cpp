#include <string>
#include <vector>
#include <map>
using namespace std;

map<int,bool> table;
int solution(vector<int> numbers) {
    int answer = 0;
    for(int i = 0;i<10;i++){
        table[i] = false;
    }
    
    for(int i = 0;i<numbers.size();i++){
        table[numbers[i]] = true;
    }
    for(int i = 0;i<10;i++){
        if(!table[i])
            answer += i;
    }
    return answer;
}