#include <iostream>
using namespace std;

int N;
char image[65][65];

void quadTree(int y, int x, int area){
    bool same = true;

    for(int i = y;i<area + y;i++){
        for(int j = x;j<area + x;j++){
            if(image[i][j] != image[y][x]){
                same = false;
                break;
            }
        }
        if(!same)
            break;
    }
    
    if(!same){
        cout<<"(";
        quadTree(y, x, area/2);
        quadTree(y, x + area/2, area/2);
        quadTree(y + area/2, x, area/2);
        quadTree(y + area/2, x + area/2, area/2);
        cout<<")";
    }
    else{
        if(image[y][x] == '0')
            cout<<0;
        else
            cout<<1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++)
            cin>>image[i][j];
    }

    quadTree(0, 0, N);
}   