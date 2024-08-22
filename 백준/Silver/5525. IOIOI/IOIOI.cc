#include <iostream>
#include <string>
using namespace std;

int N, M, answer = 0;
string S;
string P = "I";
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin>>N>>M;
    cin>>S;
    
    for(int i = 0;i<M;i++){
        int k = 0;
        if(S[i] == 'O')
            continue;
        
        while(S[i + 1] == 'O' && S[i+2] == 'I'){
            k++;
            if(k == N){
                answer++;
                k--;
            }
            i += 2;
        }

    }

    cout<<answer;
}