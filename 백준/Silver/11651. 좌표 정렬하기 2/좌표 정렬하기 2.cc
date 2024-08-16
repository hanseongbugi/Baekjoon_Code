#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
bool bigger(pair<int,int>a, pair<int,int>b){
    if(a.second == b.second){
        return a.first<b.first;
    }
    else{
        return a.second < b.second;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<pair<int,int>> v;
    cin>>N;
    int x, y;
    for(int i = 0;i<N;i++){
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),bigger);
    for(int i = 0;i<v.size();i++)
        cout<<v[i].first<<' '<<v[i].second<<'\n';
}