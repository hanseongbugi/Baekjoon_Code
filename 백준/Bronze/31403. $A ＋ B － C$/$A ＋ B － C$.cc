#include <iostream>
#include <cmath>
using namespace std;


int A, B, C;

int operator-(string a, string b){
    return stoi(a) - stoi(b);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin>>A>>B>>C;

    cout<< A + B - C <<'\n';

    cout<<to_string(A) + to_string(B) - to_string(C)<<'\n';
}