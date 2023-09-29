#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<bool> stu;
    stu.assign(30,false);
    for(int i =0;i<28;i++){
        int N;
        cin>>N;
        stu[N-1]=true;
    }
    for(int i =0;i<stu.size();i++){
        if(!stu[i]){
            cout<<i+1<<'\n';
        }
    }
}