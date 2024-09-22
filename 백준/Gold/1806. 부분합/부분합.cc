#include <iostream>
using namespace std;

int N, S;
int arr[100001];
int answer = 987654321;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N>>S;
    for(int i = 0;i<N;i++)
        cin>>arr[i];
    
    
    int s = 0, e = 0;
    int sum = 0;
    while(e<=N){
        if(sum >= S){
            answer = min(answer,(e - s));
            sum -= arr[s++];
        }
        else{
            sum += arr[e++];
        }
    }
    if(answer == 987654321)
        answer = 0;
    
    cout<<answer;
}   