#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    string temp[3]{"4", "1", "2"};
    while (n) {
        answer = temp[n % 3]+ answer;
        if (!(n % 3))
            n = n / 3 - 1;
        else
            n = n/3;
    }
    return answer;
}