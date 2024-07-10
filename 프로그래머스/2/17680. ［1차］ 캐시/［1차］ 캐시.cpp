#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string calc(string s){
    string temp = "";
    for(int i = 0;i<s.length();i++){
        if(s[i] >= 'a' && s[i] <= 'z')
            temp += s[i];
        else
            temp += (s[i] + 32); 
    }
    return temp;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> cache;

    if(cacheSize <= 0)
        return cities.size() * 5;
    
    for(int i = 0;i<cities.size();i++){
        string city = cities[i];
        city = calc(city);
        auto it = find(cache.begin(),cache.end(), city);
        if(it != cache.end()){ // cache hit
            cache.erase(it);
            cache.push_back(city);
            answer++;
        }
        else{ // cache miss
            // 캐시에 공간이 있을 때
            if(cache.size() < cacheSize){
                cache.push_back(city);
            }
            // 캐시에 공간이 없을 때
            else{
                cache.erase(cache.begin());
                cache.push_back(city);
            }
            answer+=5;
        }
    }
    return answer;
}