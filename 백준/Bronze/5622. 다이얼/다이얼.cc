#include<iostream>
#include<map>
using namespace std;

int main(){
    map<char,int> call;
    call['A'] = 2; call['B'] = 2; call['C'] = 2;
    call['D'] = 3; call['E'] = 3; call['F'] = 3;
    call['G'] = 4; call['H'] = 4; call['I'] = 4;
    call['J'] = 5; call['K'] = 5; call['L'] = 5;
    call['M'] = 6; call['N'] = 6; call['O'] = 6;
    call['P'] = 7; call['Q'] = 7; call['R'] = 7; call['S'] = 7;
    call['T'] = 8; call['U'] = 8; call['V'] = 8; 
    call['W'] = 9; call['X'] = 9; call['Y'] = 9; call['Z'] = 9;
    string number;
    int sum = 0;
    cin>>number;
    for(int i =0;i<number.length();i++){
        char c = number.at(i);
        sum += call[c];
    }
    sum += number.length();
    cout<<sum<<'\n';
}