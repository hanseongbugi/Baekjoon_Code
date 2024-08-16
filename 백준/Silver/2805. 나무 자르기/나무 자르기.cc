#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

long long N,M;
int arr[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N>>M;

    for(int i = 0;i<N;i++)
        cin>>arr[i];

    sort(arr, arr + N);

    long long low = 0;
    long long high = arr[N - 1];
    long long answer = 0;

    while(low <= high){
        long long sum = 0;
        long long cnt = (low + high) / 2;

        for(int i = 0;i<N;i++){
            if(arr[i] - cnt > 0)
                sum += arr[i] - cnt;
        }
        if(sum >= M){
            answer = cnt;
            low = cnt + 1;
        }
        else{
            high = cnt - 1;
        }
    }
    cout<<answer<<'\n';
}