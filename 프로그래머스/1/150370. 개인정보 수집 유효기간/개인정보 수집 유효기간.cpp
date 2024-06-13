#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> privaciy;
map<char, int> term;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    int year = stoi(today.substr(0, 4)); 
    int month = stoi(today.substr(5, 2)); 
    int day = stoi(today.substr(8, 2));
    int total = year * 12 * 28 + (month - 1) * 28 + day;
    
    for(int i = 0;i<terms.size();i++){
        char type = terms[i][0];
        int day = stoi(string(terms[i].begin()+2,terms[i].end()));
        term[type] = day;
    }
    
    for(int i = 0; i < privacies.size(); i++){
        int y = stoi(privacies[i].substr(0, 4)); 
        int m = stoi(privacies[i].substr(5, 2)); 
        int d = stoi(privacies[i].substr(8, 2));
        char t = privacies[i].back();
        int tmp = y * 12 * 28 + (m - 1) * 28 + d + (term[t] * 28 - 1);
        
        privaciy.push_back(tmp);
    }
    
    // 비교
    for(int i = 0; i < privaciy.size(); i++){
        if(privaciy[i] < total){
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}