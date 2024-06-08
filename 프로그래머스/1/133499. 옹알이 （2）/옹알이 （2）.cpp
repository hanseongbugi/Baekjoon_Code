#include <string>
#include <vector>

using namespace std;

bool babblingTest(string str){
    if(str == "aya" || str == "ye" || str == "woo" || str == "ma")
        return true;
    else
        return false;
}

int solution(vector<string> babbling) {
    int answer = 0;
    for(int i = 0;i<babbling.size();i++){
        string word = babbling[i];
        string temp = "";
        vector<string> words;
        for(int j = 0;j<word.length();j++){
            temp += word[j]; 
            if(babblingTest(temp)){
                words.push_back(temp);
                temp = "";
            }
        }
        if(!temp.empty())
            words.push_back(temp);
        string before = "";
        bool isSpeak = false;
        for(int j = 0;j<words.size();j++){
            if(babblingTest(words[j])){
                if(!before.empty() && words[j] == before){
                    isSpeak = false;
                    break;
                }
                isSpeak = true;
                before = words[j];
            }
            else{
                isSpeak = false;
                break;
            }
        }
        if(isSpeak)
            answer++;
    }
    return answer;
}