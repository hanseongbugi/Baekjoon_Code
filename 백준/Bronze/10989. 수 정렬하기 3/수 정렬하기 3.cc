#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned int N;
    cin>>N;
    int input;
    int count[10001] = {0};
    for(int i = 0; i < N; i++)
    {
        cin>>input;
        count[input]++;
    }

    for(int i = 0; i < 10001; i++)
        for(int j = 0; j < count[i]; j++)
            cout<<i<<'\n';
}