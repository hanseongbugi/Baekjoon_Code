#include<iostream>
#include<map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,M;
    map<long long,int> cards;
    cin>>N;
    for(int i = 0;i<N;i++){
        long long input;
        cin>>input;
        if(cards.find(input) != cards.end())
            cards[input]+=1;
        else
            cards[input] = 1;
    }
    cin>>M;
    for(int i = 0;i<M;i++){
        long long input;
        cin>>input;
        if(cards.find(input) != cards.end())
            cout<<cards[input]<<' ';
        else
            cout<<0<<' ';
    }
}