#include <iostream>

using namespace std;

int N;
int score[3];
int minDp[3];
int maxDp[3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    int temp0, temp1, temp2;

    
    for(int i = 0;i<N;i++){
        cin>>score[0]>>score[1]>>score[2];

        // 이전 정보  기록
        temp0 = minDp[0];
        temp1 = minDp[1];
        temp2 = minDp[2];

        // 최소 경로 계산
        minDp[0] = min(temp0, temp1) + score[0];
        minDp[1] = min(temp2, min(temp0, temp1)) + score[1];
        minDp[2] = min(temp1, temp2) + score[2];

        // 이전 정보 기록
        temp0 = maxDp[0];
        temp1 = maxDp[1];
        temp2 = maxDp[2];

        // 최대 경로 계산
        maxDp[0] = max(temp0, temp1) + score[0];
        maxDp[1] = max(temp2, max(temp0, temp1)) + score[1];
        maxDp[2] = max(temp1, temp2) + score[2];

    }
    cout<<max(max(maxDp[0],maxDp[1]),maxDp[2])<<' ';
    cout<<min(min(minDp[0],minDp[1]),minDp[2]);
}   