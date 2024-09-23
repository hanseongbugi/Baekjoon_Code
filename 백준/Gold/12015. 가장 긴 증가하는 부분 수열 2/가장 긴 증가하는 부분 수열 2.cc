#include <iostream>
#include <vector>
using namespace std;

int N;
int A[1000000];
int answer;
vector<int> result;

int binary(int key){
    int st = 0, en = result.size() - 1;
    while(st < en){
        int mid = (st + en) / 2;
        if(key > result[mid])
            st = mid + 1;
        else
            en = mid;
    }
    return en;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    for(int i = 0;i<N;i++)
        cin>>A[i];
    
    result.push_back(A[0]);
    answer = 1;
    for(int i = 1;i<N;i++){
        if(result.back() < A[i]){
            result.push_back(A[i]);
            answer++;
        }
        else{
            int idx = binary(A[i]);
            result[idx] = A[i];
        }
    }
    cout<<answer;
    
}   