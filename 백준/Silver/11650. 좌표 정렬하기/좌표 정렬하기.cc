#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Point{
public:
    int x;
    int y;
    Point(int x, int y):x(x),y(y){}
};
bool bigger(Point a, Point b){
    if(a.x==b.x)return a.y < b.y;
    else return a.x < b.x;
}
int main(){
    int N;
    cin>>N;
    vector<Point> arr;
    for(int i = 0;i<N;i++){
        int x,y;
        cin>>x>>y;
        arr.emplace_back(x,y);
    }
    sort(arr.begin(),arr.end(),bigger);
    for(int i = 0;i<arr.size();i++)
        cout<<arr[i].x<<' '<<arr[i].y<<'\n';
}