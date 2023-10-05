#include<iostream>
#include<vector>
using namespace std;

int calc(int num){
    if(num == 0) return 0;

    vector<int> twoArr;
    vector<int> fiveArr;
    int len = 0;
    for(int i = 1;i<=num;i++){
        int count = i;
        while(count >= 5){
            if(count%5!=0) break;
            count = count/5;
            len += 1;
        }
    }
    return len;
}

int main(){
    int N;
    cin>>N;
    int result = calc(N);

    cout<<result<<'\n';
}