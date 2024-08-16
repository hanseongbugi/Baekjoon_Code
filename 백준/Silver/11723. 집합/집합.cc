#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int M;
bool arr[21] = {false, };
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>M;
    
    string command;
    int num;
    for(int i = 0;i<M;i++){
        cin>>command;

        if(command == "add"){
            cin>>num;
            arr[num] = true;
        }
        if(command == "remove"){
            cin>>num;
            arr[num] = false;
        }
        
        if(command == "check"){
            cin>>num;
            if(arr[num])
                cout<<1<<'\n';
            else
                cout<<0<<'\n';
        }
        if(command == "toggle"){
            cin>>num;
            arr[num] = !arr[num];
        }
        if(command == "all")
            memset(arr,true,sizeof(arr));
        if(command == "empty")
            memset(arr,false,sizeof(arr));
    }
}