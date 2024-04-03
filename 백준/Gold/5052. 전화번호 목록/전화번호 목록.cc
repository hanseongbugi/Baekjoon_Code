#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int T, N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> T;
    for(int test_case = 0; test_case < T; test_case++){
        int n; cin >> n;
        string str;
        vector<string> v;
        
        for(int i = 0; i<n; i++){
            cin >> str;
            v.push_back(str);
        }

        sort(v.begin(), v.end());
        bool flag = true;
        for(int i = 0; i<v.size()-1; i++){
            string cur = v[i];
            string next = v[i+1];
            flag = true;
            if(cur.length() > next.length()) continue;
            if(cur == next.substr(0, cur.length())){
                flag = false;
                break;
            }
        }
        if(!flag) cout << "NO\n";
        else cout << "YES\n";
    }
 
    return 0;
}