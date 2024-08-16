#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
int arr[1000001];
vector<int> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N;

    int x;
    for(int i = 0;i<N;i++){
        cin>>x;
        arr[i] = x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()),v.end());
    for(int i = 0;i<N;i++){
        int target = arr[i];
        auto iter = lower_bound(v.begin(),v.end(),target);

        cout<<iter - v.begin()<<' ';
    }
}