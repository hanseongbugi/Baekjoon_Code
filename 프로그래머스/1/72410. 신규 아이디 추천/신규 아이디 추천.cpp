#include <string>
#include <vector>

using namespace std;

string test = "~!@#$%^&*()=+[{]}:?,<>/";

string solution(string new_id) {
    string answer = "";
    
    // 1, 2 단계
    for(int i = 0;i<new_id.length();i++){
        if(new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] += 32;
        
        for(int j = 0;j<test.length();j++)
            if(new_id[i] == test[j]){
                new_id.erase(new_id.begin()+i);
                i--;
            }
    }
    // 3단계
    for(int i = 1; i < new_id.length(); ){
        if (new_id[i] == '.' && new_id[i - 1] == '.'){
            new_id.erase(new_id.begin() + i);
            continue;
        }
        else i++;
    }
    // 4단계
    if(new_id[0] == '.') 
        new_id.erase(new_id.begin());
    if(new_id[new_id.length() - 1] == '.') 
        new_id.erase(new_id.begin() + new_id.length() - 1);
    // 5단계
    if(new_id.empty()) new_id = "a";
    // 6단계
    if(new_id.length() > 15){
        new_id = string(new_id.begin(), new_id.begin() + 15);
        if(new_id[new_id.length() - 1] == '.')
            new_id.erase(new_id.begin() + new_id.length() - 1);
    }
    // 7단계
    while(new_id.length()<3)   
        new_id += new_id[new_id.length() - 1];
    
    answer = new_id;
    return answer;
}