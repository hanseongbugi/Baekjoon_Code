#include<iostream>
using namespace std;

int main(){
    int N;
    cin>>N;
    int i = 0, count=666;
    while(true){
        string number = to_string(count);
        bool numberCount1 = false,numberCount2 = false,numberCount3 = false;
        for(int k = 0;k<number.size();k++){
            if(number[k]=='6'&&!numberCount1){
                numberCount1 = true;
                k+=1;
            }
            if(number[k]=='6'&&!numberCount2) {
                numberCount2 = true;
                k+=1;
            }
            if(number[k]=='6'&&!numberCount3) {
                numberCount3 = true;
            }
            if(numberCount1&&numberCount2&&numberCount3){
                i+=1;
                break;
            }
            numberCount1 = false;
            numberCount2 = false;
            numberCount3 = false;
        }
       
        if(i==N) break;
        count++;
    }
    cout<<count<<'\n';
}