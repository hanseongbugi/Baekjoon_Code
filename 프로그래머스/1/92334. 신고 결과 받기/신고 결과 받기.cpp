#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string,vector<string>> table;
map<string,int> targetTable;
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for(int i = 0;i<id_list.size();i++){
        string name = id_list[i];
        targetTable[name] = 0;
    }

    for(int i = 0;i<report.size();i++){
        int pos = 0;
        for(int j = 0;j<report[i].length();j++)
            if(report[i][j] == ' ') pos = j;
        
        string reporter = report[i].substr(0, pos);
        string target = report[i].substr(pos + 1);
        table[reporter].push_back(target);
    }
    // "abc" : {"abd", "add"}
    // "acd" : {"abd"}
    // "add" : {"abd"}
    // "abd" : {}
    
    // "abc" 
    // "acd"
    // "add" 1
    // "abd" 3
    
    for(int i = 0;i<id_list.size();i++){
        string name = id_list[i];
        
        if(!table[name].empty()){
            sort(table[name].begin(),table[name].end());
            table[name].erase(unique(table[name].begin(),table[name].end()),table[name].end());
            for(int j = 0;j<table[name].size();j++){
                targetTable[table[name][j]]++;
            }
        }
    }
    
    for(int i = 0;i<id_list.size();i++){
        string name = id_list[i];
        int count = 0;
        for(int j = 0;j<table[name].size();j++){
            if(targetTable[table[name][j]]>=k) count++;
        }
        answer.push_back(count);
    }
    
    
    return answer;
}