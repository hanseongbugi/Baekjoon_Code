#include <iostream>
#include <vector>
using namespace std;

int N;
int arr[1000001];
int NGE[1000001];
vector<int> v;

int main() {

    cin>>N;

    int A;
    for(int i = 0;i<N;i++)
        cin>>arr[i];
    
    // 7 2 5 3
    for(int i = N-1;i>=0;i--){
        while(!v.empty() && v.back() <= arr[i]){
            v.pop_back();
        }
        if(v.empty())
            NGE[i] = -1;
        else
            NGE[i] = v.back();

        v.push_back(arr[i]);
    }
    for(int i = 0;i<N;i++)
        cout<<NGE[i]<<' ';
    
}