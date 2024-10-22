#include <iostream>
using namespace std;

int L;
string text, pattern;
int table[1000001];

int main() {
    cin>>L;
    cin>>text;

    pattern = text;
    int idx = 0;
    for(int i = 1;i<L;i++){
        while(idx>0 && pattern[idx] != text[i])
            idx = table[idx - 1];
        if(pattern[idx] == text[i])
            table[i] = ++idx;
    }
    cout<<L - table[L-1];
}
