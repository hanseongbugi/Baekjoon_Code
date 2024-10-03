#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    
    // 보조 컨테니어는 가장 마지막에 보관한 상자만 뺄 수 있음
    vector<int> tempContainer;
    int idx = 0;
    
    // 컨테이너 벨트는 순차적으로 전달
    for(int i = 1;i<=order.size();i++){
        if(i == order[idx]){
            answer++;
            idx++;
        }
        // 맨앞 상자가 실어야하는 순서가 아니면 잠시 다른곳(보조 컨테이너)에 보관
        else{
            tempContainer.push_back(i);
        }
        while(!tempContainer.empty()){
            if(tempContainer.back() != order[idx])
                break;
            
            answer++;
            idx++;
            tempContainer.pop_back();
        }
    }
    // 보조 컨테이너를 사용해도 원하는 순서대로 싣지 못하면 상자를 싣지 않음
   
    
	
    return answer;
}