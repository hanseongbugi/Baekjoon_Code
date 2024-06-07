#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
vector<int> match;
int N, L, W;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    // 최저 : 0인 경우가 다 틀렸을 때
    // 최고 : 0인 경우가 다 맞았을 때 (단, 중복이 안될경우)
    N = lottos.size();

    int maxRank = 0, minRank = 0;
    int zeroNum = 0;
    for(int i = 0;i<N;i++){
        int num = count(lottos.begin(),lottos.end(),win_nums[i]);
        if(num > 0)
            minRank++;
    }
    for(int i = 0;i<N;i++){
        if(lottos[i] == 0)
            zeroNum++;
    }
    
    maxRank = minRank + zeroNum;

    if(minRank < 2) minRank = 1;
    if(maxRank == 0) maxRank = 1;
    answer.push_back(7 - maxRank);
    answer.push_back(7 - minRank);
    return answer;
}