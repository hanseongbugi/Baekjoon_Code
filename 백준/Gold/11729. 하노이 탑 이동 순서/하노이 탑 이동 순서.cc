#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> answer;

void hanoi(int n, int start, int to, int bypass)
{
    if(n == 1){
        answer.push_back({start, to});
        return;
    }

    hanoi(n-1,start,bypass,to);
    answer.push_back({start, to});
    hanoi(n-1,bypass,to,start);

}
int main() {

    cin >> N;
    hanoi(N,1,3,2);

    cout<<answer.size()<<'\n';
    for(auto e : answer){
        cout<<e.first<<' '<<e.second<<'\n';
    }
}