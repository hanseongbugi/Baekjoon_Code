#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N;
struct bigger{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)){
            return a > b;
        }
        else
            return (abs(a) > abs(b));
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	cin>>N;
    int num;
    priority_queue<int, vector<int>, bigger> q;
    for(int i = 0;i<N;i++){
        cin>>num;

        if(num == 0){
            if(q.empty())
                cout<<0<<'\n';
            else{
                cout<<q.top()<<'\n';
                q.pop();
            }
        }
        else{
            q.push(num);
        }
    }
}