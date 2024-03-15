#include<iostream>
#include<algorithm>
using namespace std;
 
int N, C, M;
int result = 0;
vector<pair<pair<int, int>, int>> arr;
int dp[2001];


bool bigger(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b){
    return a.first.second < b.first.second;
}
 
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

    cin>>N>>C;

    cin>> M;

    int a, b, c;
    for(int i = 0;i<M;i++){
        cin>>a>>b>>c;
        arr.push_back({{a,b},c});
    }
    sort(arr.begin(),arr.end(), bigger);

    for(int i = 0;i<arr.size();i++){
        int start = arr[i].first.first - 1;
        int end = arr[i].first.second - 1;
        int box = arr[i].second;
        int temp = 0;
        int counter = 0;

        for(int j = start; j < end; j++){
            temp = max(temp, dp[j]);
        }
        if(temp + box <= C) counter = box;
        else counter = C - temp;

        for(int j = start; j < end; j++)
            dp[j] += counter;
        
        result += counter;
    }
    cout<<result<<'\n';
}