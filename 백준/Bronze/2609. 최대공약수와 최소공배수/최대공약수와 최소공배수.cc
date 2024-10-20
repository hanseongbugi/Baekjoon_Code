#include <iostream>
#include <vector>
using namespace std;

int n1, n2;
int ans1 = 0, ans2 = 0;
vector<int> arr;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n1>>n2;

    for(int i = 1;i<=n1;i++){
        if(n1 % i == 0)
            arr.push_back(i);
    }
    for(int i = 0;i<arr.size();i++){
        if(n2 % arr[i] == 0)
            ans1 = max(ans1, arr[i]);
    }
    ans2 = ans1 * (n1 / ans1) * (n2 / ans1);

    cout<<ans1<<'\n';
    cout<<ans2<<'\n';
}
