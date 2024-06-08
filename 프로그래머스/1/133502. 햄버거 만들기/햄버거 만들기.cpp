#include <string>
#include <vector>

using namespace std;
vector<int> box;

int solution(vector<int> ingredient) {
    int answer = 0;
    
    for(int i = 0;i<ingredient.size();i++){
        box.push_back(ingredient[i]);
        if(ingredient[i] == 1 && box.size() > 3){
            int t1 = box.back();
            box.pop_back();
            int t2 = box.back();
            box.pop_back();
            int t3 = box.back();
            box.pop_back();
            int t4 = box.back();
            box.pop_back();
            if(t1 == 1 && t2 == 3 && t3 == 2 && t4 == 1)
                answer++;
            else{
                box.push_back(t4);
                box.push_back(t3);
                box.push_back(t2);
                box.push_back(t1);
            }
            
        }
    }
    return answer;
}