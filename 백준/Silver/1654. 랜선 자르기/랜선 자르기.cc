#include <iostream>
#define MAX 
using namespace std;

int main(){
    int K, N;
    long long start = 1, end, mid, sum = 0, total, max = -1;
    cin >> K >> N;

    int length[K];

    for(int i = 0 ; i < K ; i++){
        cin >> length[i];
        sum += length[i];
    }

    end = sum / N; 

    while(start <= end){
        total = 0;
        mid = (start + end) / 2;

        for(int i = 0 ; i < K ; i++){
            total += length[i] / mid;
        }

        if(total >= N){
            start = mid + 1;
            if(mid > max) max = mid;
        }
        else{
            end = mid - 1;
        }
    }

    cout << max;

    return 0;
}