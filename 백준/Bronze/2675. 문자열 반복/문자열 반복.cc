#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin>>T;
    for(int i =0;i<T;i++){
        string s;
        int R;
        cin>>R>>s;
        for(int j =0;j<s.length();j++){
            for(int k =0;k<R;k++)
                cout<<s.at(j);
        }
        cout<<'\n';
            
    }
}
