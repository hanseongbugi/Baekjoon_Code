#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
int answer;
int col[15];
void nqueen(int x){
    if(N == x)
        answer++;
    else{
        for(int i = 0;i<N;i++){
            col[x] = i;
            bool isCollision = false;

            for(int j = 0;j<x;j++){
                if(col[x] == col[j] || abs(col[x] - col[j]) == x - j){
                    isCollision = true;
                    break;
                }
            }
            if(!isCollision)
                nqueen(x + 1);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;

    nqueen(0);
    cout<<answer;
}   