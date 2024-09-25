#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    int div = 10;
    while(n != 0){
        answer += n % div; // 3, 2, 1
        
        n /= div; // 12, 1, 1
    }

    return answer;
}