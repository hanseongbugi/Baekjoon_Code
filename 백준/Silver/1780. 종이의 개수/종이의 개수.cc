#include <iostream>
using namespace std;

int N;
int paper[2200][2200];
int onePaper = 0;
int zeroPaper = 0;
int minousPaper = 0;

void FindPaper(int y, int x, int n){
    bool same = true;

    for(int  i = y;i<y+n;i++){
        for(int j = x;j<x+n;j++){
            if(paper[i][j] != paper[y][x]){
                same = false;
                break;
            }
        }
        if(!same)
            break;
    }


    if(same){
        if(paper[y][x] == 0)
            zeroPaper++;
        else if(paper[y][x] == 1)
            onePaper++;
        else
            minousPaper++;
    }
    else{
        FindPaper(y, x, n/3);
        FindPaper(y + n / 3, x, n/3);
        FindPaper(y + n / 3 + n / 3, x, n/3);
        FindPaper(y, x + n / 3, n/3);
        FindPaper(y, x + n / 3 + n / 3, n/3);
        FindPaper(y + n / 3, x + n / 3, n/3);
        FindPaper(y + n / 3, x + n / 3 + n / 3, n/3);
        FindPaper(y + n / 3 + n / 3, x + n / 3, n/3);
        FindPaper(y + n / 3 + n / 3, x + n / 3 + n / 3, n/3);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>N;
    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++)
            cin>>paper[i][j];
    }
    FindPaper(0, 0, N);

    cout<<minousPaper<<'\n';
    cout<<zeroPaper<<'\n';
    cout<<onePaper<<'\n';

}   