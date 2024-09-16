#include <iostream>
#include <string>
#include <vector>
using namespace std;

string target;
string bomb;
vector<char> v;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>target;
    cin>>bomb;

    for(int i = 0;i<target.length();i++){
        v.push_back(target[i]);

        if(v.size() >= bomb.length()){
            string str = "";
            for(int i = bomb.length();i>0;i--)
                str += v[v.size() - i];

            if(str == bomb){
                for(int i = 0;i<str.length();i++)
                    v.pop_back();
            }
        }
    }
    if(v.empty()){
        cout<< "FRULA";
        return 0;
    }
    for(int i = 0;i<v.size();i++)
        cout<<v[i];
}   