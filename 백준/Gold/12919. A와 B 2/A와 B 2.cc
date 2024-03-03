#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


void calcString(string s, string t){
    if(s==t) {
        cout<<1<<'\n';
        exit(0);
    }
    if(s.length() > t.length()) return;
    if(t[t.length() - 1] == 'A'){
        string temp = t;
        temp.pop_back();
        calcString(s,temp);
    }
    if(t[0] == 'B'){
        string temp = t;
        reverse(temp.begin(),temp.end());
        temp.pop_back();
        calcString(s,temp);
    }
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string S,T;
    cin>>S;
    cin>>T;

    calcString(S,T);

    cout<<0<<'\n';
	return 0;
}