#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
pair<int,int> arr[51];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N;
    for(int i = 0;i<N;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    int count;
    for(int i = 0;i<N;i++){
        count = 1;
        for(int j = 0;j<N;j++){
            if(arr[i].first<arr[j].first && arr[i].second < arr[j].second)
                count++;
        }
        cout<<count<<' ';
    }

}