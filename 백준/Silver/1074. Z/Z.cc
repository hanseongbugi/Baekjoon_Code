#include<iostream>
#include<cmath>
using namespace std;
int N,r,c;
int counter = 0;
void foundArea(int x,int y,int size){
    if(c==x && r == y){
        cout<<counter<<'\n';
        return;
    }
    else if(c < x + size && r< y + size && c >= x && r >= y){
        foundArea(x, y, size/2);
        foundArea(x + size/2, y, size/2);
        foundArea(x, y + size/2, size/2);
        foundArea(x + size/2, y + size/2, size/2);
    }else{
        counter += size*size;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>r>>c;
    
    foundArea(0, 0, pow(2,N));
}