#include <string>
#include <vector>
#include <iostream>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str;
    for(int i = 0;i<3;i++){
        cin>>str;

        if(str[0]=='F'||str[0] == 'B')
            continue;
        
        int num = stoi(str) + 3 - i;
        if(num % 3 && num % 5)
            cout << num;
        else{
            if(num % 3 == 0)
                cout<<"Fizz";
            if(num % 5 == 0)
                cout<<"Buzz";
        }
        break;
    }
}