#include <string>
#include <vector>

using namespace std;

int M;
string makeBinary(int n){
    string num = "";
    for(int i = 0;i<M;i++){
        num += to_string(n % 2);
        n /= 2;
    }
    return num;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<string> v;
    M = n;
    for(int i = 0;i<arr1.size();i++){
        int b = arr1[i];
        string s = makeBinary(b);
        string temp = "";
        for(int i = s.length() - 1;i>=0;i--){
            if(s[i] == '0')
                temp += " ";
            else
                temp += "#";
        }
        answer.push_back(temp);
    }
     for(int i = 0;i<arr2.size();i++){
        int b = arr2[i];
        string s = makeBinary(b);
        string temp = "";
        for(int i = s.length() - 1;i>=0;i--){
            if(s[i] == '0')
                temp += " ";
            else
                temp += "#";
        }
        v.push_back(temp);
    }
    
    for(int i = 0;i<v.size();i++){
        for(int j = 0;j<M;j++)
            if(v[i][j] != answer[i][j])
                answer[i][j] = '#';
    }
    return answer;
}