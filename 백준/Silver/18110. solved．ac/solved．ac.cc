#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double N;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N;
    if(N == 0){
        cout<<0<<'\n';
        return 0;
    }
    vector<int> v;
    int user;
    for(int i = 0;i<N;i++){
        cin>>user;
        v.push_back(user);
    }
    sort(v.begin(),v.end());

    int delNum = floor(N * 0.15 + 0.5);
    double sum = 0;
    for(int i = delNum;i<N - delNum;i++)
        sum += v[i];
    
    sum = sum / (N - delNum * 2);
    sum = floor(sum + 0.5);
    cout<<sum<<'\n';
}