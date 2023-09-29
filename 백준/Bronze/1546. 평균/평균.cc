#include <iostream>
#include <algorithm>
using namespace std;
 
int main(int argc, const char *argv[]) {
 
	ios_base::sync_with_stdio(false);
	cout.tie(0);
	int N;	
	int M = -1;	
	double sum = 0;
	cin >> N;
	double v;
	for(int i = 0; i < N; i++) {
		cin >> v;
		sum += v;	
		if(M < v) 	
			M = v;	
	}

	cout << ((sum / M) / N) * 100 ;
	return 0;
}