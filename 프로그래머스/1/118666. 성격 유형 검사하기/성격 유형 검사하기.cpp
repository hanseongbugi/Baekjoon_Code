#include <string>
#include <vector>

using namespace std;
vector<vector<pair<char,int>>> table = {{{'R',0},{'T',0}},{{'C',0},{'F',0}},{{'J',0},{'M',0}},{{'A',0},{'N',0}}};

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    for(int i = 0;i<survey.size();i++){
        int score = choices[i];
        char personal = '-';
        if(score<4){
            personal = survey[i][0];
            score = 4 - score;
        }
        else if(score == 4){
            continue;
        }
        else{
            personal = survey[i][1];
            score -= 4; 
        }
        if(personal != '-'){
            for(int j = 0;j<table.size();j++){
                if(table[j][0].first == personal){
                   table[j][0].second+=score; 
                }
                if(table[j][1].first == personal){
                    table[j][1].second+=score; 
                } 
            }
        }
    }
    for(int i = 0;i<table.size();i++){
        int type1 = table[i][0].second;
        int type2 = table[i][1].second;
        if(type1 > type2){
            answer += table[i][0].first;
        }
        else if(type1 < type2){
            answer += table[i][1].first;
        }
        else{
            answer += min(table[i][0].first,table[i][1].first);
        }
    }
    return answer;
}