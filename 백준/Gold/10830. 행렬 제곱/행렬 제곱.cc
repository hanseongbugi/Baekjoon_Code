#include <iostream>
using namespace std;

long long N, B;
long long matrix[5][5];
long long answer[5][5];
long long sum[5][5];

void calc(long long x[5][5], long long y[5][5]){
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            sum[i][j] = 0;
            for(int k = 0;k<N;k++){
                sum[i][j] += x[i][k] * y[k][j];
            }
            sum[i][j] %= 1000;
        }
    }
    for(int i = 0;i<N;i++)
        for(int j = 0;j<N;j++)
            x[i][j] = sum[i][j];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N>>B;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++)
            cin>>matrix[i][j];
        answer[i][i] = 1; // 단위 행렬
    }

    while(B > 0){ // 5 -> 2 -> 1
        if(B % 2 == 1){
            // 홀수 인 경우 정답행렬에 A행렬 곱
            calc(answer, matrix);     
        }
        // 지수법칙 사용 
        calc(matrix, matrix);

        B /= 2;
    }

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++)
            cout<<answer[i][j]<<' ';
        cout<<'\n';
    }
}   