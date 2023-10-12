#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr;
    int N,M;
    cin>>N>>M;
    arr.assign(N,0);
    for(int i = 0;i<N;i++){
        int input;
        cin>>input;
        arr[i] = input;
    }
    int result;
    int min = 9999999;
    for(int i = 0;i<N-2;i++){
        for(int j = i+1;j<N-1;j++){
            for(int k = j+1;k<N;k++){
                int sum = arr[i] + arr[j] + arr[k];
                if(M - sum < min && M - sum >= 0){
                    min = M - sum;
                    result = sum;
                }
            }
        }
    }
    cout<<result<<'\n';
}