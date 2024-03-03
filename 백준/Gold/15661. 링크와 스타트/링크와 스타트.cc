#include<iostream>
#include<vector>
using namespace std;

int N;
int ability[21][21];
bool visited[21];
int result = 987654321;

int calc(){
    int counter1 = 0;
    int counter2 = 0;
    for(int i = 0;i<N-1;i++){
        for(int j = i+1;j<N;j++){
            if(visited[i] && visited[j])
                counter1 += ability[i][j] + ability[j][i];
            
            else if(!visited[i]&&!visited[j])
                counter2 += ability[i][j] + ability[j][i];
        }
    }
    return abs(counter1- counter2);
}

void combination(int counter){
    if(counter==N){
        result = min(result, calc());
        return;
    }
    visited[counter] = true;
    combination(counter+1);
    visited[counter] = false;
    combination(counter+1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
    cin>>N;

    for(int i = 0;i<N;i++){
        for(int j = 0;j<N;j++)
            cin>>ability[i][j];
    }
    combination(0);
	cout<<result<<'\n';

	return 0;
}