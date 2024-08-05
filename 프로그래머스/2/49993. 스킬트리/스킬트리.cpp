#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char, bool> skill_map;
    for(int i = 0;i<skill.length();i++)
        skill_map[skill[i]] = true;
    
    for(int i = 0;i<skill_trees.size();i++){
        string skill_tree = skill_trees[i];
        int skillIdx = 0;
        bool isClear = true;
        for(int j = 0;j<skill_tree.length();j++){
            if(skill[skillIdx] == skill_tree[j]){
                skillIdx++;
            }
            else{
                if(skill_map[skill_tree[j]]){
                    isClear = false;
                    break;
                }
            }
        }
        if(isClear)
            answer++;
    }
    return answer;
}