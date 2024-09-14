#include <iostream>
using namespace std;

int N;
char star[6600][6600];
void makeStar(int y, int x, int area, bool pattern){
    if(area == 3){
        if(pattern){
            for(int i = y;i<area + y;i++){
                for(int j = x;j<area + x;j++){
                    if(i == (y + 1) && j == (x + 1))
                        star[i][j] = ' ';
                    else
                        star[i][j] = '*';
                }
            }
        }
        else{
            for(int i = y;i<area + y;i++){
                for(int j = x;j<area + x;j++){
                    star[i][j] = ' ';
                }
            }
        }
    }
    else{
        makeStar(y, x, area/3, pattern);
        makeStar(y + area/3, x, area/3, pattern);
        makeStar(y + area/3 + area/3, x, area/3, pattern);
        
        makeStar(y, x + area/3, area/3, pattern);
        makeStar(y + area/3, x + area/3, area/3, false);
        makeStar(y + area/3 + area/3, x + area/3, area/3, pattern);
        
        makeStar(y, x + area/3 + area/3, area/3, pattern);
        makeStar(y + area/3, x + area/3 + area/3, area/3, pattern);
        makeStar(y + area/3 + area/3, x + area/3 + area/3, area/3, pattern);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;
    makeStar(0, 0, N, true);

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++)
            cout<<star[i][j];
        cout<<'\n';
    }
}   