#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    for(int n : numbers)
        answer += n;
    answer /= static_cast<double>(numbers.size());
    return answer;
}