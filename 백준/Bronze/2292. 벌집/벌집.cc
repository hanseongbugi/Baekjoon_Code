#include <string>
#include <vector>
#include <iostream>
using namespace std;

int N;

int main(){
    cin>>N;
    
    int i = 0;
    for(int sum = 2;sum<=N;i++){
        sum += 6*i;
    }
    if(N == 1) i = 1;
    cout << i<<'\n';
}