#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
 
int counter[8001] = {0,};
 
int main(){
    int N;
    cin>>N;
    vector<int> arr;
    arr.assign(N,0);
    double avg = 0;
    for(int i = 0;i<N;i++){
        int input;
        cin>>input;
        arr[i] = input;
        avg += input;
        counter[input+4000] ++;
    }
    avg /= N; // 산술 평균 연산
    sort(arr.begin(),arr.end());
    int mid = arr[N/2]; // 중앙 값 연산
 
    int min = 0;
    int most = -9999;
    bool not_first = false;
    for(int i = 0;i<8001; i++){
        if(counter[i] == 0) continue;
        if(counter[i] == most){
            if(not_first){
                min = i - 4000;
                not_first = false;
            }
        }
        if(counter[i] > most){
            most = counter[i];
            min = i - 4000;
            not_first = true;
        }
    }
  
    int range = arr[N-1] - arr[0]; // 범위 연산
    double average = round(avg);
    if(avg < 0.5 && avg>-0.5) average = 0;
    cout<<average<<'\n';
    cout<<mid<<'\n';
    cout<<min<<'\n';
    cout<<range<<'\n';
}
