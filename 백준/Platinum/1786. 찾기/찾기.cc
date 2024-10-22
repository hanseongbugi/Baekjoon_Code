#include <iostream>
#include <vector>
using namespace std;

string T, P;
int table[1000001];
vector<int> answer;

void Failure(){
    int j = 0;

    for(int i = 1;i<P.length();i++){
        while(j>0 && P[i] != P[j])
            j = table[j - 1];
        
        if(P[i] == P[j])
            table[i] = ++j;
    }
}

void KMP(){
    int N = T.length();
    int M = P.length();
    Failure();

    int j = 0;
    for(int i = 0;i<N;i++){
        while(j>0 && T[i] != P[j]){
            j = table[j - 1];
        }
        if(T[i] == P[j]){
            if(j == M - 1){
                answer.push_back(i - M + 2);
                j = table[j];
            }
            else{
                j++;
            }
        }
    }
}


int main() {
    getline(cin,T);
    getline(cin, P);
    KMP();
    cout<<answer.size()<<'\n';
    for(int i = 0;i<answer.size();i++)
        cout<<answer[i]<<' ';
}
